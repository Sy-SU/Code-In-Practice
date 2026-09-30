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

Z pw[200005], invpw[200005];

Z C(i64 n, i64 m) {
	return pw[n] * invpw[m] * invpw[n - m];
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::map<int, i64> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	std::vector<int> func(n + 1);
	std::vector<Z> ans(n + 1);
	int idx = 0;

	Z pos = 1, neg = 1;
	for (auto [num, ct] : cnt) {
		if (num != -1) {
			func[++idx] = num;
		}
		// if (num == -1) {
		// 	continue;
		// }

		Z cse = 1;
		for (int i = 2; i <= ct; i += 2) {
			cse += C(ct, i);
		}
		pos *= cse;

		if (num != -1) {
			ans[idx] = cse;
		}
	}

	// for (int i = 1; i <= idx; i++) {
	// 	std::cerr << i << " " << func[i] << " " << ans[i] << '\n';
	// }

	std::vector<Z> preans(idx + 2), sufans(idx + 2);
	preans[0] = 1, sufans[idx + 1] = 1;
	for (int i = 1; i <= idx; i++) {
		preans[i] = preans[i - 1] * ans[i];
	}
	for (int i = idx; i >= 1; i--) {
		sufans[i] = sufans[i + 1] * ans[i];
	}

	Z ncse = 0;
	i64 cnt1 = cnt[-1];
	for (int i = 1; i <= cnt1; i += 2) {
		ncse += C(cnt1, i);
	}
	neg *= ncse;
	// std::cerr << ncse << '\n';

	Z tsum = 0;

	for (int i = 1; i < idx; i++) {
		if (func[i] + 1 != func[i + 1]) {
			continue;
		}
		i64 numi = cnt[func[i]], numi1 = cnt[func[i + 1]];
		Z csei = 0, csei1 = 0;
		for (int j = 1; j <= numi; j += 2) {
			csei += C(numi, j);
		}
		for (int j = 1; j <= numi1; j += 2) {
			csei1 += C(numi1, j);
		}
		tsum += preans[i - 1] * csei * sufans[i + 2] * csei1;
		// std::cerr <<  preans[i - 1] * csei * sufans[i + 2] * csei1 << '\n';
	}

	std::cout << pos + neg * tsum << '\n';
	// std::cerr << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	pw[0] = invpw[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		pw[i] = pw[i - 1] * i;
	}
	for (int i = 1; i <= 200000; i++) {
		invpw[i] = pw[i].inv();
	}

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}