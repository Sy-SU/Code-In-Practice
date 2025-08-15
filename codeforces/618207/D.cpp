#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<double> a(n + 1);
	for (int i = 0; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<double> dp(n + 1, 1e18), ans(n + 1);
	dp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j <= n; j++) {
			// 位于 i, 选择 j
			double e = ans[j] / (j - i) + a[j] * (j - i + 1) / (j - i);
			dp[i] = std::min(dp[i], e);
		}
		for (int j = i; j <= n; j++) {
			ans[j] += dp[i];
		}
	}
	// std::cerr << dp[0] << " " << dp[1] << " " << dp[2] << '\n';
	std::cout << std::fixed << std::setprecision(12) << dp[0] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}