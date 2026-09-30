#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<char>> map(n + 1, std::vector<char>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> map[i][j];
		}
	}

	std::vector<std::vector<int>> prewhite(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		prewhite[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			prewhite[i][j] = prewhite[i][j - 1] + (map[i][j] == '.');
		}
	}

	std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2));
	std::vector<std::vector<int>> min(n + 2, std::vector<int>(n + 2, 1e9));
	for (int j = 0; j <= n; j++) {
		min[0][j] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 0; j--) {
			dp[i][j] = min[i - 1][j] + (j + 1 - prewhite[i][j] + prewhite[i][n] - prewhite[i][j]);
			min[i][j] = std::min(min[i][j + 1], dp[i][j]);
		}
	}

	std::cout << min[n][0] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}