#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, mod;
	std::cin >> n >> mod;

	std::vector<std::vector<i64>> dp(n + 2, std::vector<i64>(n + 2));
	std::vector<i64> sum(n + 2);

	sum[0] = 1;
	dp[0][1] = 1;

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1];
		dp[i - 1][i] = sum[i - 1];
		for (int j = 1; j <= i; j++) {
			sum[i] = (sum[i] + dp[i - 1][j] * j);
		}

		
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= i; k++) {
				if (j == k) continue;
				dp[i][j] = dp[i][j] + k * dp[i - 1][j];
			}
		}

		// for (int j = 1; j < i; j++) {
		// 	dp[i][j] = dp[i - 1][j] * (1 + (i + 1) * i / 2 - j);
		// }
		dp[i][i] = sum[i] - i * sum[i - 1];
	}

	for (int i = 1; i <= 10; i++) {
		std::cerr << sum[i] << " \n"[i == 10];
	}

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= i; j++) {
			std::cerr << dp[i][j] << " \n"[j == i];
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