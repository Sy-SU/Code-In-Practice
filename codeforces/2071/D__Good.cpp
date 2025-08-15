#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, l, r;
	std::cin >> n >> l >> r;

	std::vector<i64> a(1e5, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = n + 1; i <= l; i++) {
		i64 tmp = 0;
		for (int j = 1; j <= i / 2; j++) {
			tmp ^= a[j];
		}
		a[i] = tmp;
	}
	for (int i = 1; i <= l; i++) {
		std::cerr << a[i] << " \n"[i == l];
	}
	std::cout << a[l] << '\n';
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