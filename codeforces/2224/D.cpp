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

	std::vector<i64> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	if (n == 1) {
		std::cout << 0 << '\n';
		return;
	}

	std::vector<std::pair<i64, i64>> pa, pb;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pa.push_back({a[i], a[j]});
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				pb.push_back({b[i], b[j]});
			}
		}
	}

	std::sort(pa.begin(), pa.end(), [](std::pair<i64, i64> p1, std::pair<i64, i64> p2) {
		return p1.first * p2.second < p1.second * p2.first;
	});

	std::sort(pb.begin(), pb.end(), [](std::pair<i64, i64> p1, std::pair<i64, i64> p2) {
		return p1.first * p2.second < p1.second * p2.first;
	});

	int sz = pb.size();

	Z ans = 0;
	Z pw = 1;
	for (int i = 1; i <= n - 2; i++) {
		pw *= i;
	}

	for (auto [ai, aj] : pa) {
		// std::cerr << ai <<  " " << aj << '\n';
		int lo = 0, hi = sz - 1, fd = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			auto [by, bx] = pb[mid];

			if (ai * bx > aj * by) {
				lo = mid + 1;
				fd = mid;
			} else {
				hi = mid - 1;
			}
		}

		// std::cerr << fd + 1 << '\n';

		ans += (fd + 1) * (Z)1 * pw;
	}

	// std::cerr << ans << '\n';

	pw *= (n - 1);
	pw *= n;

	ans *= pw.inv();

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