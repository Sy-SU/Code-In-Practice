#include <bits/stdc++.h>

using i64 = long long;
#define int long long

constexpr int N = 2e5 + 10;

void solve() {
	int n, m, l;
	std::cin >> n >> m >> l;

	std::vector<int> a(l + 1);
	for (int i = 1; i <= l; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> edge(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
	}

	std::vector<std::vector<int>> mindis(n + 1, std::vector<int>(2, 1e18));
	mindis[1][0] = 0;
	std::queue<int> q;
	std::vector<int> inq(n + 1);
	q.push(1);
	inq[1] = 1;
	while (!q.empty()) {
		int now = q.front();
		// std::cerr << "vis" << now << " " << mindis[now][0] << " " << mindis[now][1] << '\n';
		q.pop();
		inq[now] = 0;
		for (const auto &to : edge[now]) {

			if (mindis[to][0] <= mindis[now][1] + 1 && mindis[to][1] <= mindis[now][0] + 1) {
				continue;
			}
			mindis[to][0] = std::min(mindis[to][0], mindis[now][1] + 1);
			mindis[to][1] = std::min(mindis[to][1], mindis[now][0] + 1);
			if (inq[to]) {
				continue;
			}
			q.push(to);
			// std::cerr << "====\n" ;
			// std::cerr << now << "->" << to << '\n';
			// std::cerr << mindis[to][0] << " " << mindis[to][1] << '\n';
			// std::cerr << mindis[now][0] << " " << mindis[now][1] << '\n';
			// std::cerr << "====\n" ;
			inq[to] = 1;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << "node " << i << " " << mindis[i][0] << " " << mindis[i][1] << '\n';
	// }

	i64 sum = 0;
	for (int i = 1; i <= l; i++) {
		sum += a[i];
	}

	i64 max[2];
	if (sum % 2) {
		max[1] = sum;
		// 最小奇数
		int minodd = 1e18;
		for (int i = 1; i <= l; i++) {
			if (a[i] % 2 == 0) {
				continue;
			}
			minodd = std::min(minodd, a[i]);
		}
		max[0] = sum - minodd;
	} else {
		max[0] = sum;
		int minodd = 1e18;
		for (int i = 1; i <= l; i++) {
			if (a[i] % 2 == 0) {
				continue;
			}
			minodd = std::min(minodd, a[i]);
		}
		max[1] = sum - minodd;	
	}

	for (int i = 1; i <= n; i++) {
		std::cout << (mindis[i][0] <= max[0] || mindis[i][1] <= max[1]);
	}
	std::cout << '\n';

}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}