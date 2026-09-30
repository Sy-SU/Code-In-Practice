#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string a, b;
	std::cin >> a >> b;

	int n = a.size(), m = b.size();
	a = " " + a, b = " " + b;

	std::vector<int> A(n + 1), B(m + 1);
	for (int i = 1; i <= n; i++) {
		A[i] = A[i - 1] + (a[i] - '0');
		A[i] %= 10;
	}
	for (int i = 1; i <= m; i++) {
		B[i] = B[i - 1] + (b[i] - '0');
		B[i] %= 10;
	}

	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			dp[i][j] = std::max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
		}
	}

	if (A[n] != B[m]) {
		std::cout << -1 << '\n';
		return;
	}
	std::cout << dp[n][m] << '\n';
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