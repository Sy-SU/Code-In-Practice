#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<std::vector<char>> map(n + 1, std::vector<char>(m + 1));

	int cntg = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 'g') {
				cntg++;
			}
		}
	}

	std::vector<std::vector<int>> pre(n + 1, std::vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (map[i][j] == 'g');
		}
	} 

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		std::cerr << pre[i][j] << " \n"[j == m];
	// 	}
	// }

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != '.') {
				continue;
			}

			int x1 = i - k + 1, x2 = i + k - 1;
			int y1 = j - k + 1, y2 = j + k - 1;

			x1 = std::max(1, x1), x2 = std::min(n, x2);
			y1 = std::max(1, y1), y2 = std::min(m, y2);

			
			int del = pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1];
			// std::cerr << x1 << " " << y1 << " " << x2 << " " << y2 << " " << del << '\n';

			ans = std::max(ans, cntg - del);
		}
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