#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	s = " " + s;

	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2 * n + 4, -1e9));
	dp[0][n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int d = n + 1 - i; d <= n + 1 + i; d++) {
			for (int j = 0; j <= i - 1; j++) {
				if (j == i - 2) {
					continue;
				}
				// std::cerr << j << " " << d - (s[i] == '1' ? 1 : -1) << '\n';
				dp[i][d] = std::max(dp[i][d], dp[j][d - (s[i] == '1' ? 1 : -1)] + 1);
				// std::cerr << "dp" << i << " " << d - n - 1 << " = " << dp[i][d] << '\n';
			}	
		}
	}

	int ans = 1e9;
	for (int i = 0; i <= n; i++) {
		if (i != n - 1) {
			ans = std::min(ans, n - dp[i][n + 1]);
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