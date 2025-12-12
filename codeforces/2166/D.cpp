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

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	std::sort(cnt.begin() + 1, cnt.end(), std::greater<int>());

	Z ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= (cnt[i] + 1);
	}

    int sta = -1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] != cnt[1]) {
            sta = i;
            break;
        }
    }

    if (sta == -1) {
        std::cout << ans - 1 << '\n';
        return;
    }

    int end = 0;
    for (int i = 1; i <= n; i++) {
        end = i - 1;
        if (cnt[i] == 0) {
            break;
        }
    }

    std::vector<std::vector<Z>> dp(2, std::vector<Z>(n + 1));
    dp[(sta - 1) & 1][0] = 1;

    for (int i = sta; i <= end; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i & 1][j] = dp[!(i & 1)][j];
            if (j >= cnt[i]) {
                dp[i & 1][j] += dp[!(i & 1)][j - cnt[i]] * cnt[i];
            }
        }
    }

    for (int i = 0; i < cnt[1]; i++) {
        ans -= dp[end & 1][i];
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