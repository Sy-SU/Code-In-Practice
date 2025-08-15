#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> mat(n + 1, std::vector<int>(m + 1));
	std::vector<std::pair<int, int>> w;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> mat[i][j];
			if (mat[i][j]) {
				w.push_back({i, j});
			}
		}
	}

	std::vector<std::vector<int>> dist(n + 1, std::vector<int>(m + 1, 1e9));
	for (auto [x, y] : w) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dist[i][j] = std::min(dist[i][j], std::abs(i - x) + std::abs(j - y));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cout << dist[i][j] << " \n"[j == m];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}