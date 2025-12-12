#include <bits/stdc++.h>

using i64 = long long;

constexpr int maxn = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<std::vector<int>> adj(n + 1);
	std::vector<int> d(n + 1);
	for (int i = 1; i < n; i++) {
		int p;
		std::cin >> p;

		adj[p].push_back(i + 1);
		d[p]++, d[i + 1]++;
	}

	std::vector<int> dep(n + 1);

	auto dfs = [&](auto &&self, int u, int f) -> void {
		dep[u] = dep[f] + 1;
		for (auto v : adj[u]) {
			self(self, v, u);
		}
	};

	dfs(dfs, 1, 0);

	int maxd = 1e9;
	for (int i = 2; i <= n; i++) {
		if (d[i] == 1) {
			maxd = std::min(maxd, dep[i]);
		}
	}

	std::vector<int> cost(n + 1);
	for (int i = 1; i <= n; i++) {
		cost[dep[i]]++;
	}

	int sum = 0;
	for (int i = 1; i <= maxd; i++) {
		sum += cost[i];
	}

	std::bitset<maxn> dp;

	dp[0] = 1;
	for (int i = 1; i <= maxd; i++) {
		dp |= (dp << cost[i]);
	}

	if (sum <= k || sum <= n - k) {
		std::cout << maxd << '\n';
		return;
	}

	for (int i = 0; i <= sum; i++) {
		if (i >= std::max(0, k - (n - sum)) && i <= std::min(k, sum) && dp[i]) {
			std::cout << maxd << '\n';
			return;
		}
	}

	std::cout << maxd - 1 << '\n';
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