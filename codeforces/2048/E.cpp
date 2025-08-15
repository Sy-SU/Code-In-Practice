#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;
	if (2 * n <= m) {
		std::cout << "NO" << '\n';
		return;
	}

	std::vector<std::vector<int>> ans(2 * n + 1, std::vector<int>(2 * n - 1 + 1, 0));

	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * n - 1; j++) {
			int del = i - j;
			del = (del + 2 * n) % (2 * n);
			ans[i][j] = (del + 2) / 2;
		}
	}

	std::cout << "YES" << '\n';
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cout << ans[i][j] << " \n"[j == m];
		}
	}
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