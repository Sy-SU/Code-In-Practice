#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<std::set<int>> dp(n + 1);

	int nodecnt = n * n * n;
	std::vector<std::vector<int>> edge(nodecnt + 1);

	// i, sum -> i + sum * (n + 1)
	dp[0].insert(0);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			// j + 1 ~ i
			int len = i - j;
			int add = len * (len - 1) / 2;

			for (auto cnt : dp[j]) {
				dp[i].insert(cnt + add); // ok[i][cnt + add]
				int u = j + cnt * (n + 1), v = i + (cnt + add) * (n + 1);
				edge[v].push_back(u);
			}
		}
	}

	int fail = n * (n - 1) / 2 - k;
	// n, fail
	int sta = n + fail * (n + 1);
	if (edge[sta].empty()) {
		std::cout << 0 << '\n';
		return;
	}

	std::vector<int> ans(n + 1);
	int low = 1;

	int now = sta;
	while (1) {
		// std::cerr << now << '\n';
		int to = edge[now][0];
		// to + 1 ~ now

		int l = to % (n + 1) + 1, r = now % (n + 1);
		for (int i = l; i <= r; i++) {
			ans[i] = low++;
		}

		if (to == 0) {
			break;
		}

		now = to;
	}

	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << " \n"[i == n];
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