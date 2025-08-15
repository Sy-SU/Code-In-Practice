#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(k + 1, -1e18));

	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int pre = std::max(0, i - 6); pre < i; pre++) {
				if (j) {
					dp[i][j] = std::max(dp[i][j], dp[pre][j - 1] + a[i]);
				}
			}
		}
	}

	i64 ans = -1e18;
	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, dp[i][k]);

	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}