#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> adj(n + 1);
	std::vector<int> d(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
		d[u]++, d[v]++;
	}

	std::vector<std::vector<int>> node(n + 1);
	for (int i = 1; i <= n; i++) {
		node[d[i]].push_back(i);
	}

	std::vector<int> ans(n + 1, 1e9);
	std::vector<int> inq(n + 1);
	for (int i = n; i >= 1; i--) {
		std::queue<int> q;
		for (auto u : node[i]) {
			q.push(u);
			inq[u] = 1;
		}

		while (!q.empty()) {
			auto now = q.front();
			q.pop();
			inq[now] = 0;

			for (auto to : adj[now]) {
				int at = ans[to];

				if (i > d[to]) {
					ans[to] = std::min(ans[to], ans[now] + 1);
					if (d[now] == i) {
						ans[to] = 1;
					}
				}

				if (at > ans[to] && inq[to] == 0) {
					inq[to] = 1;
					q.push(to);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i] >= 1e6) {
			ans[i] = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << " \n"[i == n];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}