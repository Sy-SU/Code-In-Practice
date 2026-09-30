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
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> pre(m + 1);
	for (int now = 1; now <= m; now++) {
		for (int i = 1; i < now; i++) {
			int g = std::gcd(now, i);
			if (now / g - i / g == 1) {
				pre[now].push_back(i);
			}
		}
	}

	pre[1].push_back(0);

	std::vector<std::vector<Z>> dp(n + 1, std::vector<Z>(m + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			// 只能转移到 a[i]
			int now = a[i];
			for (auto p : pre[now]) {
				dp[i][now] += dp[i - 1][p];
			}
		} else {
			for (int j = 1; j <= m; j++) {
				int now = j;
				for (auto p : pre[now]) {
					dp[i][now] += dp[i - 1][p];
				}
			}
		}
	}

	Z ans = 0;
	for (int now = 1; now <= m; now++) {
		ans += dp[n][now];
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