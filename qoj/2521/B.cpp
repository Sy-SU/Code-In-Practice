#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int d, ind;
	bool operator > (const Node &n) const {
		return d > n.d;
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> adj(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i < n; i++) {
		std::string str;
		std::cin >> str;
		for (int j = 0; j < n - i; j++) {
			// i -> j + 1
			if (str[j] == '1') {
				// std::cerr << i << " -> " << i + j + 1 << '\n';
				adj[i][i + j + 1] = 1;
			} else {
				// std::cerr << i + j + 1 << " -> " << i << '\n';
				adj[i + j + 1][i] = 1;
			}
		}
	}

	std::vector<std::vector<int>> dist(n + 1, std::vector<int>(n + 1, 1e9));
	
	for (int s = 1; s <= n; s++) {
		dist[s][s] = 0;
		std::vector<int> need, now;
		for (int i = 1; i <= n; i++) {
			if (i != s) {
				need.push_back(i);
			} else {
				now.push_back(i);
			}
		}
		while (1) {
			if (now.empty() || need.empty()) {
				break;
			}
			std::vector<int> nextnow;
			for (auto ct : need) {
				for (auto nw : now) {
					if (adj[nw][ct] == 0) {
						continue;
					}
					if (dist[s][nw] + 1 >= dist[s][ct]) {
						continue;
					}
					dist[s][ct] = dist[s][nw] + 1;
					nextnow.push_back(ct);
					break;
				}
			}
			now = nextnow;
			std::vector<int> tmpneed;
			for (auto e : need) {
				if (dist[s][e] >= 1e6) {
					tmpneed.push_back(e);
				}
			}
			need = tmpneed;
		}
	}

	while (m--) {
		int x, y;
		std::cin >> x >> y;
		if (dist[x][y] >= 1e6) {
			std::cout << -1 << '\n';
		} else {
			std::cout << dist[x][y] - 1 << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}