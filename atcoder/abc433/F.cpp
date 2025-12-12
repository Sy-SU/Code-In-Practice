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

Z pw[1000005];

Z C(i64 n, i64 m) {
	return pw[n] * pw[m].inv() * pw[n - m].inv();
}

void solve() {
	pw[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		pw[i] = pw[i - 1] * i;
	}

	std::string s;
	std::cin >> s;

	int n = s.size();
	s = " " + s;

	std::vector<std::vector<int>> precnt(n + 2, std::vector<int>(10));
	for (int i = 1; i <= n; i++) {
		for (int d = 0; d <= 9; d++) {
			precnt[i][d] = precnt[i - 1][d] + (s[i] == ('0' + d));
		}
	}

	Z ans = 0;
	for (int i = 1; i <= n; i++) {
		int d = s[i] - '0';
		if (d == 9) {
			continue;
		}
		int pre = precnt[i - 1][d], suf = precnt[n][d + 1] - precnt[i][d + 1];
		ans += C(pre + suf, pre + 1);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}