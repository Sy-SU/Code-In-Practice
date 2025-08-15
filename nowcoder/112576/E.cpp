#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> lst(2 * n + 1), vis(n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		if (vis[a[i]] == 0) {
			vis[a[i]] = i, lst[i] = -1;
		} else {
			lst[i] = vis[a[i]];
		}
	}

	std::vector<i64> pre(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	std::vector<i64> dp(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		dp[i] = dp[i - 1];
		if (lst[i] == -1) {
			continue;
		}
		dp[i] = std::max(dp[i], dp[lst[i] - 1] + pre[i] - pre[lst[i] - 1]);
	}
	std::cout << dp[2 * n] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}