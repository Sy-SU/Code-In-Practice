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

Z pw[200005];

Z C(i64 n, i64 m) {
	Z res = pw[n] / pw[m] / pw[n - m];
	return res;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = n; i > (n + 1) / 2; i--) {
		if (a[i]) {
			std::cout << 0 << '\n';
			return;
		}
	}

	Z ans = 1;
	i64 res = 0;
	for (int i = (n + 1) / 2; i >= 1; i--) {
		if (n % 2 && i == (n + 1) / 2) {
			res++;
		} else {
			res += 2;
		}
		if (a[i] > res) {
			std::cout << 0 << '\n';
			return;
		}
		ans = ans * C(res, a[i]);
		res -= a[i];
	}
	if (res) {
		std::cout << 0 << '\n';
		return;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	pw[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		pw[i] = pw[i - 1] * (Z)i;
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}