#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 x, s;
	std::cin >> n >> x >> s;

	std::string str;
	std::cin >> str;

	str = " " + str;

	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(x + 1));
	for (int j = 1; j <= x; j++) {
		dp[0][j] = -1e18;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (str[i] == 'I') {
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
			} else if (str[i] == 'E') {
				if (dp[i - 1][j] < j * 1ll * s) {
					dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + 1);
				}
			} else {
				if (dp[i - 1][j] < j * 1ll * s) {
					dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + 1);
				} 
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}

	i64 ans = 0;

	for (int j = 0; j <= x; j++) {
		ans = std::max(ans, dp[n][j]);
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