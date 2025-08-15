#include <bits/stdc++.h>

using i64 = long long;

int dp[100][100];

void solve() {
	i64 n, m;
	std::cin >> n >> m;

	dp[1][1] = 1, dp[2][2] = 2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j]) {
				continue;
			}
			dp[i][j] = dp[i - 1][j] * (j - 2) + dp[i - 2][j] * (j - 1) + dp[i - 1][j - 1] + dp[i - 2][j - 1];
		}
	}
	std::cout << dp[n][m] << '\n'; 
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}