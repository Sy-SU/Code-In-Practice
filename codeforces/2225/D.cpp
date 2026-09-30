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

using Z = ModInt<998244353>;

void solve() {
	i64 n, x;
	std::cin >> n >> x;

	auto f = [&](i64 x) -> std::pair<Z, Z> {
		Z ans1 = 0, ans3 = 0;
		return {(x + 3) / 4, (x + 1) / 4 + 1};
	};

	auto [l1, l3] = f(x - 1);
	auto [r1, r3] = f(n);

	r1 -= l1, r3 -= l3;

	Z ans = l1 * r1 + l3 * r3;
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