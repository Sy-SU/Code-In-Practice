#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::vector<int> s(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
	}

	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(4));

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
		if (s[i] == s[i - 1]) {
			dp[i][2] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
		} else if (s[i] + s[i - 1] == 0) {
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
		}
		dp[i][3] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
		// std::cerr << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << '\n';
	}

	i64 ans = (dp[n][0] + dp[n][1]) % mod;
	std::cout << ans << '\n';
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