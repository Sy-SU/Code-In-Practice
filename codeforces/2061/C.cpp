#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;

i64 dp[N][2];

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][0];
		if (a[i] == a[i - 1]) {
			dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
		}
		if (i >= 2 && a[i] == a[i - 2] + 1) {
			dp[i][0] = (dp[i][0] + dp[i - 2][0]) % mod;
		}
	}
	std::cout << (dp[n][0] + dp[n][1]) % mod << '\n';

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