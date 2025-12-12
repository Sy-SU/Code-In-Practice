#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += c[i];
	}

	std::vector<i64> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) {
				continue;
			}
			dp[i] = std::max(dp[i], dp[j] + c[i]);
		}
	}

	for (int i = 2; i <= n; i++) {
		dp[i] = std::max(dp[i], dp[i - 1]);
	}

	std::cout << sum - dp[n] << '\n';
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