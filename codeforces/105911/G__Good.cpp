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
	
	std::queue<NODE> q;
	std::map<NODE, bool> inqueue;
	for (int sta = 1; sta <= n; sta++) {
		q.push({sta, sta, 0});
		inqueue[{sta, sta, 0}] = 1;
	}

	while (!q.empty()) {
		auto [now, sta, dep] = q.front();
		q.pop();

		// std::cerr << "bfs" << now << " " << sta << " " << dep << '\n';

		if (maxcost[sta][dep] >= 1e12) {
			continue;
		}

		inqueue[{now, dep}] = 1;

		for (auto [to, w] : edge[now]) {
			if (inqueue[{to, sta, dep + 1}]) {
				continue;
			}
			q.push({to, sta, dep + 1});
			inqueue[{to, sta, dep + 1}];
			maxcost[sta][dep + 1] = std::max(maxcost[sta][dep + 1], maxcost[sta][dep] * w + w - 1);
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int d = 1; d <= 3; d++) {
	// 		std::cerr << maxcost[i][d] << " \n"[d == 3];
	// 	}
	// }

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