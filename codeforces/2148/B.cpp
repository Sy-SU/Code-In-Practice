#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, x, y;
	std::cin >> n >> m >> x >> y;

	std::vector<int> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}

	std::cout << n + m << '\n';
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