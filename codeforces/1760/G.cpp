#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, a, b;
	std::cin >> n >> a >> b;

	std::vector<std::vector<std::pair<int, int>>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;

		edge[u].push_back({v, w}), edge[v].push_back({u, w});
	}

	std::vector<int> prea(n + 1), preb(n + 1);

	auto dfsa = [&](auto &&self, int u, int fa) -> void {
		for (auto [v, w] : edge[u]) {
			if (v == fa || v == b) {
				continue;
			}
			prea[v] = prea[u] ^ w;
			self(self, v, u);
		}
	};	

	dfsa(dfsa, a, 0);

	std::map<int, bool> vis;
	for (int i = 1; i <= n; i++) {
		if (i == b) {
			continue;
		}
		vis[prea[i]] = 1;
	}

	auto dfsb = [&](auto &&self, int u, int fa) -> void {
		for (auto [v, w] : edge[u]) {
			if (v == fa) {
				continue;
			}
			preb[v] = preb[u] ^ w;
			self(self, v, u);
		}
	};

	dfsb(dfsb, b, 0);

	for (int i = 1; i <= n; i++) {
		if (i == b) {
			continue;
		}
		if (vis[preb[i]]) {
			std::cout << "Yes" << '\n';
			return;
		}
	}

	std::cout << "No" << '\n';
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