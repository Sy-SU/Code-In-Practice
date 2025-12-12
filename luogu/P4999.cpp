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

using Z = ModInt<1000000007>;

void solve() {
	i64 l, r;
	std::cin >> l >> r;

	auto calc = [&](i64 x) -> Z {
		std::vector<int> a; // x 的每一个数位
		i64 tmp = x;
		while (tmp) {
			a.push_back(tmp % 10);
			tmp /= 10;
		}

		std::reverse(a.begin(), a.end());
		int len = a.size(); // x 的长度

		std::vector<std::vector<Z>> f(20, std::vector<Z>(200, -1));

		auto dp = [&](auto &&self, int pos, bool limit, int sum) -> Z {
			if (pos == len) {
				return sum;
			}
			if (limit == 0 && f[pos][sum] != -1) {
				return f[pos][sum];
			}
			Z res = 0;
			if (limit) {
				// 如果已经达到限制
				for (int i = 0; i <= 9; i++) {
					if (i < a[pos]) {
						res += self(self, pos + 1, 0, sum + i);
					} else if (i == a[pos]) {
						res += self(self, pos + 1, 1, sum + i);
					} else {
						break;
					}
				}
			} else {
				for (int i = 0; i <= 9; i++) {
					res += self(self, pos + 1, 0, sum + i);
				}
			}

			if (limit == 0) {
				f[pos][sum] = res;
			}

			return res;
		};

		return dp(dp, 0, 1, 0);
	};

	std::cout << calc(r) - calc(l - 1) << '\n';
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