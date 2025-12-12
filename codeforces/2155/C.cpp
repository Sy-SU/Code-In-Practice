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

using Z = ModInt<676767677>;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> sta(n + 1);

	int ans = 0;

	int cnt = 1;
	sta[1] = 0; // l
	for (int i = 2; i <= n; i++) {
		if (std::abs(a[i] - a[i - 1]) >= 2) {
			std::cout << 0 << '\n';
			return;
		}
		if (a[i] - a[i - 1] == -1) {
			if (sta[i - 1] != 1) {
				cnt = 0;
			} else {
				sta[i] = 1;
			}
		} else if (a[i] - a[i - 1] == 1) {
			if (sta[i - 1] != 0) {
				cnt = 0;
			} else {
				sta[i] = 0;
			}
		} else {
			sta[i] = 1 - sta[i - 1];
		}
	}

	// std::cerr << "case l : ";
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << sta[i] << " \n"[i == n];
	// }

	int ok = 1;
	for (int i = 2; i <= n; i++) {
		ok += sta[i];
	}
	if (ok != a[1]) {
		cnt = 0;
	}

	ans += cnt;

	cnt = 1;
	sta[1] = 1; // r
	for (int i = 2; i <= n; i++) {
		if (std::abs(a[i] - a[i - 1]) >= 2) {
			std::cout << 0 << '\n';
			return;
		}
		if (a[i] - a[i - 1] == -1) {
			if (sta[i - 1] != 1) {
				cnt = 0;
			} else {
				sta[i] = 1;
			}
		} else if (a[i] - a[i - 1] == 1) {
			if (sta[i - 1] != 0) {
				cnt = 0;
			} else {
				sta[i] = 0;
			}
		} else {
			sta[i] = 1 - sta[i - 1];
		}
	}

	// std::cerr << "case r : ";
	// for (int i = 1; i <= n; i++) {
	// 	std::cout << sta[i] << " \n"[i == n];
	// }

	ok = 1;
	for (int i = 2; i <= n; i++) {
		ok += sta[i];
	}
	if (ok != a[1]) {
		cnt = 0;
	}

	ans += cnt;

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