#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 m;
	std::cin >> m;

	std::vector<i64> a(m + 1);
	for (int i = 1; i <= m; i++) {
		a[i] = m - i;
	}

	std::vector<std::vector<i64>> dp(m + 1, std::vector<i64>(6));
	for (int i = 1; i <= m; i++) {
		for (int u = 0; u <= 5; u++) {
			dp[i][u] = dp[i - 1][u] + a[i];
			if (u && i - u * 3 >= 0) {
				dp[i][u] = std::max(dp[i][u], dp[i - 3][u - 1] + (i - u * 3) * (m - i));
			}
		}
	}
	i64 ans = 0;
	for (int u = 0; u <= 5; u++) {
		ans = std::max(ans, dp[m][u]);
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