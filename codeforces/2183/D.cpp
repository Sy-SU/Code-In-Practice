#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
	}

	std::vector<int> d(n + 1), fa(n + 1);
	auto dfs = [&](auto &&self, int u, int f) -> void {
		d[u] = d[f] + 1;
		fa[u] = f;
		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
		}
	};

	dfs(dfs, 1, 0);

	std::vector<std::vector<int>> vd(n + 1);
	for (int i = 1; i <= n; i++) {
		vd[d[i]].push_back(i);
	}

	int ans = 0;
	for (int d = 1; d <= n; d++) {
		int sz = vd[d].size();
		int bonus = 1;

		for (int i = 0; i < sz; i++) {
			int u = vd[d][i];
			if (fa[u] != fa[vd[d][0]]) {
				bonus = 0;
			}
		}

		ans = std::max(ans, sz + bonus);
	}
	std::cout << ans << '\n';
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