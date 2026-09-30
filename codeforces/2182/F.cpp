#include <bits/stdc++.h>

using i64 = long long;

template<int MOD>
struct ModInt {
    static_assert(MOD > 0, "MOD must be positive");

    int v;

    ModInt() : v(0) {}
    template<class T>
    ModInt(T x) {
        long long t = (long long)x % MOD;
        if (t < 0) t += MOD;
        v = (int)t;
    }

    static constexpr int mod() { return MOD; }
    int val() const { return v; }

    ModInt& operator+=(const ModInt& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& o) {
        v = (int)((__int128)v * o.v % MOD);
        return *this;
    }
    ModInt& operator/=(const ModInt& o) {
        return *this *= o.inv();
    }

    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }
    ModInt operator-() const { return ModInt(v ? MOD - v : 0); }

    friend bool operator==(const ModInt& a, const ModInt& b) { return a.v == b.v; }
    friend bool operator!=(const ModInt& a, const ModInt& b) { return a.v != b.v; }

    ModInt pow(long long e) const {
        ModInt res = 1, base = *this;
        while (e > 0) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }

    ModInt inv() const {
        return pow(MOD - 2);
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& a) {
        return os << a.v;
    }
    friend std::istream& operator>>(std::istream& is, ModInt& a) {
        long long x; is >> x;
        a = ModInt(x);
        return is;
    }
};

using Z = ModInt<998244353>;

i64 pw[6100];
Z fact[1005];

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	std::sort(c.begin() + 1, c.end(), std::greater<i64>());

	while (m--) {
		int o;
		i64 x;
		std::cin >> o >> x;

		if (o == 1) {
			c.push_back(x);
			n++;
			std::sort(c.begin() + 1, c.end(), std::greater<i64>());
		} else if (o == 2) {
			auto it = std::find(c.begin() + 1, c.end(), x);
			c.erase(it);
			n--;
			std::sort(c.begin() + 1, c.end(), std::greater<i64>());
		} else {
			Z ans = 0;

			std::vector<std::map<i64, Z>> dp(n + 1);
			dp[0][0] = 1;
			for (int i = 1; i <= n; i++) {
				std::vector<std::map<i64, Z>> next(n + 1);
				for (int j = 0; j <= std::min(60, n); j++) {
					for (auto [sum, cnt] : dp[j]) {
						if (cnt == 0) {
							continue;
						}
						next[j][sum] += cnt;
						next[j + 1][sum + pw[c[i]] / pw[j]] += cnt;
					}
				}
				for (int j = 0; j <= std::min(60, n); j++) {
					dp[j].clear();
					for (auto [sum, cnt] : next[j]) {
						if (i < n && sum < x - pw[c[i + 1]] / pw[j] * 2) {
							continue;
						}
						if (sum >= x) {
							ans += fact[n - i] * next[j][sum];
							continue;
						}
						dp[j][sum] = cnt;
					}
				}
			}

			std::cout << ans << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	pw[0] = 1;
	for (int i = 1; i <= 60; i++) {
		pw[i] = pw[i - 1] * 2;
	}

	fact[0] = 1;
	for (int i = 1; i <= 1000; i++) {
		fact[i] = fact[i - 1] * 2;
	}

	solve();

	return 0;
}