#include <bits/stdc++.h>

using i64 = long long;

// struct NODE {
// 	int node;
// 	i64 wait, run;
// 	bool operator < (const NODE &n1) const {
// 		return ((wait + run) == (n1.wait + n1.run)) ? (wait < n1.wait) : ((wait + run) < (n1.wait + n1.run));
// 	}
// };

struct NODE {
	int node;
	i64 wait, run;
	bool operator > (const NODE &n1) const {
		return ((wait + run) == (n1.wait + n1.run)) ? (wait > n1.wait) : ((wait + run) > (n1.wait + n1.run));
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> edge(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
	}

	std::map<std::pair<int, int>, std::pair<i64, i64>> dist;

	std::priority_queue<NODE, std::vector<NODE>, std::greater<NODE>> pq;
	for (int i = 0; i < (int)edge[1].size(); i++) {
		pq.push({1, i, 0});
		dist[{1, i}] = {0, 0};
	}
	while (!pq.empty()) {
		auto [now, wait, run] = pq.top();
		pq.pop();

		i64 t = wait + run;
		int to = edge[now][t % (int)edge[now].size()];



		int sz = edge[to].size();
		for (int w = 0; w < sz; w++) {
			i64 torun = run + 1, towait = wait + w;
			std::cerr << now << " " << wait  << "->" << to << " " <<towait << '\n';
			std::pair<i64, i64> cost = {torun + towait, towait};
			if (cost < dist[to]) {
				dist[to] = cost;
				pq.push({to, towait, torun});
			}
		}
	}

	std::cout << dist[n].first << " " << dist[n].second << '\n';
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