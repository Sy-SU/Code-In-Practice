#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;
constexpr int N = 1e5 + 10;

i64 pw[N];

i64 qpow(i64 a, i64 b, i64 p) {
	i64 res = 1;
	while (b)
	{
		if (b & 1)
			res = (res * a) % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

i64 inv(i64 x, i64 p) {
	return qpow(x, p - 2, p);
}

i64 C(i64 n, i64 m) {
	i64 res = 1;
	for (i64 i = 0; i < m; i++) {
		res = ((n - i) % mod * res) % mod;

	}
	for (i64 i = 1; i <= m; i++) {
		res = (res * inv(i, mod)) % mod;
	}

	return res;
}

void solve() {
	i64 a, b, k;
	std::cin >> a >> b >> k;

	i64 n = ((a - 1) * k + 1);

	// std::cerr << n << '\n';

	i64 m = (C(n, a) * (b - 1) % mod * k % mod + 1) % mod;

	n %= mod;

	std::cout << n << " " << m << '\n';
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