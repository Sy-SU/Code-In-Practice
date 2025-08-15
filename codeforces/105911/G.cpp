#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

struct NODE {
	int now, sta, dep;
	bool operator < (NODE n) const {
		return (now == n.now ? (sta == n.sta ? dep < n.dep : sta < n.sta) : now < n.now);
	}
};

void solve() {
	int n, m, Q;
	std::cin >> n >> m >> Q;

	std::vector<std::vector<std::pair<int, i64>>> edge(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		i64 w;
		std::cin >> u >> v >> w;

		edge[u].push_back({v, w});
	}

	std::vector<std::vector<i64>> maxcost(n + 1, std::vector<i64>(31));
	
	for (int dep = 1; dep <= 30; dep++) {
		for (int u = 1; u <= n; u++) {
			for (auto [v, w] : edge[u]) {
				maxcost[u][dep] = std::max(maxcost[u][dep], maxcost[v][dep - 1] * w + w - 1); 
				if (maxcost[u][dep] >= 1e9) {
					maxcost[u][dep] = 1e9;
				}
			}
		}
	}

	while (Q--) {
		int p;
		i64 x;
		std::cin >> p >> x;

		int ans = 0;
		for (int i = 1; i <= 30; i++) {
			if (maxcost[p][i] >= x) {
				ans = i;
				break;
			}
		}
		std::cout << ans << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}	