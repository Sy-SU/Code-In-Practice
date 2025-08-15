#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e6 + 10;

int dp[2][N];

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<int> t(n + 1);
	for (int i = 1; i <= n; i++) {
		int con = 0;
		for (int j = 1; j <= k; j++) {
			int x;
			std::cin >> x;
			con |= (1 << (x - 1));
		}
		t[i] = con;
	}

	for (int i = 0; i < 2; i++) {
		for (int v = 0; v < (1 << m); v++) {
			dp[i][v] = 1e9;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int v = 0; v < (1 << m); v++) {
			dp[i & 1][v] = 1e9;
		}
		for (int v = 0; v < (1 << m); v++) {
			dp[i & 1][v | t[i]] = std::min(dp[i & 1][v | t[i]], dp[!(i & 1)][v] + 1);
			dp[i & 1][v] = std::min(dp[i & 1][v], dp[!(i & 1)][v]);
		}
	}
	int ans = std::min(dp[0][(1 << m) - 1], dp[1][(1 << m) - 1]);
	std::cout << (ans <= n ? ans : -1) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}