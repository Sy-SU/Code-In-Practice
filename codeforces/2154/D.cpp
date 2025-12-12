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

	std::vector<std::pair<int, int>> op;
	std::vector<int> dep(n + 1);

	auto dfs = [&](auto &&self, int u, int f) -> void {
		dep[u] = dep[f] + 1;
		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
		}
	};

	dfs(dfs, n, 0);

	std::vector<std::vector<int>> d(n + 1);
	for (int i = 1; i <= n; i++) {
		d[dep[i]].push_back(i);
	}

	int now = dep[1] % 2;
	for (int i = n; i >= 1; i--) {
		if (d[i].empty()) {
			continue;
		}
		
		if (i == 1) {
			break;
		}
		for (auto u : d[i]) {
			op.push_back({1, 0});
			if (now % 2 != i % 2) {
				op.push_back({1, 0});
			} else {
				now = now ^ 1;
			}
			op.push_back({2, u});
		}
	}

	std::cout << op.size() << '\n';
	for (auto [o, x] : op) {
		if (o == 1) {
			std::cout << o << '\n';
		} else {
			std::cout << o << " " << x << '\n';
		}
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