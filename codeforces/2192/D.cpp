#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
	}

	std::vector<i64> cost(n + 1), sum(n + 1), depth(n + 1);
	auto dfs1 = [&](auto &&self, int u, int f) -> void {
		sum[u] = a[u];
		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
			sum[u] += sum[v];
			cost[u] += sum[v] + cost[v]; //
			depth[u] = std::max(depth[u], depth[v] + 1);
		}

		// cost[u] = sum[u] - a[u];
		// for (auto v : adj[u]) {
		// 	if (v == f) {
		// 		continue;
		// 	}
		// 	self(self, v, u);
		// 	cost[u] += cost[v];
		// }
	};

	dfs1(dfs1, 1, 0);

	std::vector<i64> ans(n + 1), bonus(n + 1);

	auto dfs2 = [&](auto &&self, int u, int f) -> void {
		ans[u] = cost[u];
		int maxd1 = -1, maxd2 = -1;
		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
			if (depth[v] >= maxd1) {
				maxd2 = maxd1, maxd1 = depth[v];
			} else if (depth[v] >= maxd2) {
				maxd2 = depth[v];
			}
		}

		// if (u == 2) {
		// 	std::cerr << maxd1 << " " << maxd2 << '\n';
		// }

		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			// self(self, v, u);
			if (depth[v] == maxd1) {
				// ans[u] = std::max(ans[u], cost[u] + (maxd2 + 1) * sum[v]);
				bonus[u] = std::max({bonus[u], bonus[v], (maxd2 + 1) * sum[v]});
			} else {
				// ans[u] = std::max(ans[u], cost[u] + (maxd1 + 1) * sum[v]);
				bonus[u] = std::max({bonus[u], bonus[v], (maxd1 + 1) * sum[v]});
			}
		}
	};

	dfs2(dfs2, 1, 0);

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << ans[i] << " " << bonus[i] << '\n';
	// }

	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] + bonus[i] << " \n"[i == n];
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