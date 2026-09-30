#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k, v;
	std::cin >> n >> k >> v;

	std::vector<std::vector<int>> adj(n + 1);
	std::vector<int> d(n + 1);

	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
		d[u]++, d[v]++;
	}

	int r = v;

	std::vector<int> M1(n + 1, 1e9), M2(n + 1, 1e9); // m1 <= m2

	std::vector<int> blk(n + 1);

	for (int i = 1; i <= n; i++) {
		if (d[i] == 1) {
			blk[i] = 1;
		}
	}

	while (1) {
		auto cp = blk;

		std::vector<int> m1(n + 1, 1e9), m2(n + 1, 1e9); // m1 <= m2

		auto dfs = [&](auto &&self, int u, int f) -> void {
			if (blk[u]) {
				m1[u] = 0;
				return;
			}
			for (auto v : adj[u]) {
				if (v == f) {
					continue;
				}
				self(self, v, u);
				if (m1[v] + 1 < m1[u]) {
					m2[u] = m1[u], m1[u] = m1[v] + 1;
				} else if (m1[v] + 1 < m2[u]) {
					m2[u] = m1[v] + 1;
				} else {
					if (m2[v] + 1 < m1[u]) {
						m2[u] = m1[u], m1[u] = m2[v] + 1;
					} else if (m2[v] + 1 < m2[u]) {
						m2[u] = m2[v] + 1;
					}
				}				
			}
		};

		dfs(dfs, r, 0);

		for (int i = 1; i <= n; i++) {
			if (k > m1[i] + m2[i] - 2) {
				blk[i] = 1;
			}
		}

		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << m1[i] + m2[i] << " \n"[i == n];
		// }

		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << blk[i] << " \n"[i == n];
		// }

		if (cp == blk) {
			M1 = m1, M2 = m2;
			break;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << blk[i] << " \n"[i == n];
	// }
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << M1[i] + M2[i] << " \n"[i == n];
	// }

	if (blk[v]) {
		std::cout << "YES" << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (blk[i]) {
			continue;
		}
		if (k > M1[i] + M2[i] - 2) {
			std::cout << "YES" << '\n';
			return;
		}
	}

	std::cout << "NO" << '\n';
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