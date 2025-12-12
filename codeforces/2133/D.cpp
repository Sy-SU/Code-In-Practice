#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> h(n + 3);
	for (int i = 1; i <= n; i++) {
		std::cin >> h[i];
	}

	std::vector<i64> dp(n + 2);
	dp[1] = h[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = std::min(h[i - 1] + std::max(0ll, h[i] - (i - 1)) + dp[i - 2], dp[i - 1] + h[i] - 1);
	}
	std::cout << dp[n] << '\n';
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