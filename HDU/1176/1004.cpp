#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

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

	std::vector<int> q(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> q[i];
	}

	std::vector<i64> k(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> k[i];
	}

	i64 ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = (ans * i) % mod;
	}

	std::cout << qpow(ans, m, mod) << '\n';
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