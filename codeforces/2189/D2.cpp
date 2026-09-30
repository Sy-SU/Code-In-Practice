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
	int n, c;
	std::cin >> n >> c;

	std::string s;
	std::cin >> s;

	s = " " + s;

	if (s[1] == '?') {
		s[1] = '1';
	}
	if (s[n] == '?') {
		s[n] = '1';
	}

	if (s[1] == '0' || s[n] == '0') {
		std::cout << -1 << '\n';
		return;
	}

	std::vector<int> cand;

	Z ans = 1;
	for (int i = 2; i <= n; i++) {
		Z mul = 1;
		int m = 1;
		if (s[i] == '1') {
			m = 2;
			mul = 2;
		} else if (s[i] == '0') {
			m = (i - 1);
			mul = (i - 1);
		} else {
			cand.push_back(i - 1);
		}
		ans *= mul;

		int g = std::gcd(c, m);
		c /= g;
	}

	if (c == 1) {
		std::cout << -1 << '\n';
		return;
	}

	int base = 1;
	while (c % (base * 2) == 0) {
		base *= 2;
	}

	std::reverse(cand.begin(), cand.end());

	std::vector<int> h;
	for (auto can : cand) {
		if (can % 2 == 0) {
			h.push_back(can);
		}
	}
	for (auto can : cand) {
		if (can % 2 == 1) {
			h.push_back(can);
		}
	}

	cand = h;

	// std::cerr << ans << " " << c << '\n';

	if (base == c) {
		for (auto can : cand) {
			if (can % 2 == 0) {
				ans *= 2;
				int g = std::gcd(2, c);
				c /= g;
			} else {
				if (can != 1) {
					if (c == 2) {
						ans *= can;
						int g = std::gcd(can, c);
						c /= g;
					} else {
						ans *= 2;
						int g = std::gcd(2, c);
						c /= g;
					}
				}
			}
		}
	} else {
		for (auto can : cand) {
			ans *= std::min(can, 2);
		}
	}

	if (c == 1) {
		std::cout << -1 << '\n';
		return;
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