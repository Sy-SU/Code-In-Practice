#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

i64 qpow(i64 a, i64 b, i64 p) {
	i64 res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

i64 inv(i64 x, i64 p) {
	return qpow(x, p - 2, p);
}

void solve() {
	i64 n, m;
	std::cin >> n >> m;

	i64 ans = 1;
	for (i64 x = n * (n - 1) + m; x >= n * (n - 1) + 1; x--) {
		ans = (x % mod * ans) % mod;
	}
	for (i64 x = m; x >= 1; x--) {
		ans = (ans * inv(x, mod)) % mod;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}