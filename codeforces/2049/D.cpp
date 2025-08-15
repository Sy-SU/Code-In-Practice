#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 200 + 10;

i64 dp[N][N][N];

void solve() {
	int n, m;
	i64 k;
	std::cin >> n >> m >> k;

	std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1, -1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int s = 0; s <= m; s++) {
				dp[i][j][s] = 1e16;
			}
		}
	}
	for (int s = 0; s < m; s++) {
		dp[1][0][s] = k * s;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int s = 0; s < m; s++) {
				dp[i][j][s] = dp[i][j - 1][s] + a[i][(j + s - 1) % m + 1];
				for (int t = 0; t < m; t++) {
					dp[i][j][s] = std::min(dp[i][j][s], dp[i - 1][j][t] + a[i][(j + s - 1) % m + 1] + k * s);
				}
			}
		}
	}
	// std::cerr << dp[1][1][0] << " " << dp[1][2][0] << " " << dp[2][2][0] << " " << dp[2][3][0] << '\n';
	i64 ans = 1e16;
	for (int s = 0; s < m; s++) {
		ans = std::min(ans, dp[n][m][s]);
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