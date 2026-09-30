#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(n + 1));
	// dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (a[i] == j && b[i] == j) {
				dp[i][j] += dp[i - 1][j - 1]; 
				if (j == 1) {
					dp[i][j]++;
				}
			}
			if (a[i] != j + 1 && b[i] != j + 1) {
				dp[i][j] += dp[i - 1][j];
				if (j == 0) {
					dp[i][j]++;
				}
			}
		}
	} 
	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			sum += dp[i][j];
			// std::cerr << "dp " << i << " " << j << " = " << dp[i][j] << '\n';
		}
	}

	std::cout << sum << '\n';
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