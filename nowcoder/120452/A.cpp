#include <bits/stdc++.h>

using i64 = long long;

template<int MOD>
struct ModInt {
    /*
    using Z = ModInt<998244353>;

    int main() {
        Z a = 2, b = 3;
        cout << a + b << "\n";    // 5
        cout << a * b << "\n";    // 6
        cout << a / b << "\n";    // 2 * inv(3)
        cout << a.pow(10) << "\n"; // 1024
    }
    */

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

using Z = ModInt<1000000007>;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<char>> map(n + 1, std::vector<char>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
		}
	}

	std::vector<std::vector<Z>> dp(n + 1, std::vector<Z>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = 1;
			} else {
				if (map[i - 1][j] == 'D' || map[i - 1][j] == 'B') {
					dp[i][j] += dp[i - 1][j];
				} 
				if (map[i][j - 1] == 'R' || map[i][j - 1] == 'B') {
					dp[i][j] += dp[i][j - 1];
				}
			}
		}
	}

	std::cout << dp[n][m] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}