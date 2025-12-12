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

constexpr int mod = 1e9 + 7;
using Z = ModInt<mod>;

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<int> c(n + 1);
	for (int i = 1; i <= k; i++) {
		int x;
		std::cin >> x;
		c[x] = 1;
	}

	if (m == 1) {
		std::cout << 1 << '\n';
		return;
	}

	// m = 2
	std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>>(1 << n, std::vector<int>(2)));
	dp[1][0][0] = 0, dp[1][1][0] = 1, dp[1][0][1] = 0, dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int s = 0; s < (1 << i); s++) {
			dp[i & 1][s][1] = 1, dp[i & 1][s][0] = 0;
		}
		for (int s = 0; s < (1 << i); s++) {
			for (int j = 0; j < i; j++) {
				if (c[j + 1] == 0) {
					continue;
				}
				// s, j -> nxt
				int nxt = ((s >> (j + 1)) << j) + s % (1 << j);
				dp[i & 1][s][0] |= dp[!(i & 1)][nxt][1];
				dp[i & 1][s][1] &= dp[!(i & 1)][nxt][0];
			}
		}
	}

	Z ans = 0;
	for (int s = 0; s < (1 << n); s++) {
		ans += 1 + dp[n & 1][s][0];
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}