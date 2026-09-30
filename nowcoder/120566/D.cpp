#include <bits/stdc++.h>

using i64 = long long;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

struct Node {
	int x, y;
	i64 t;
	bool operator > (Node n) const {
		return t > n.t;
	}
};

void solve() {
	int n, m, a, b;
	std::cin >> n >> m >> a >> b;

	std::vector<std::pair<int, int>> blk(a + 1);
	for (int i = 1; i <= a; i++) {
		int x, y;
		std::cin >> x >> y;

		blk[i] = {x, y};
	}

	std::vector<std::vector<i64>> map(n + 1, std::vector<i64>(m + 1));
	for (int i = 1; i <= b; i++) {
		int x, y;
		i64 t;
		std::cin >> x >> y >> t;

		map[x][y] = t;
	}

	std::vector<std::vector<i64>> stp(n + 1, std::vector<i64>(m + 1, -1));
	std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
	for (int i = 1; i <= a; i++) {
		auto [x, y] = blk[i];
		q.push({x, y, 0});
		stp[blk[i].first][blk[i].second] = 0;
	}

	while (!q.empty()) {
		auto [x, y, nows] = q.top();
		q.pop();

		// std::cerr << "vis" << x << " " << y << " " << stp[x][y] << '\n';

		for (int d = 0; d < 4; d++) {
			int tox = x + dx[d], toy = y + dy[d];
			if (tox < 1 || tox > n || toy < 1 || toy > m) {
				continue;
			}
			if (stp[tox][toy] <= nows + 1 && stp[tox][toy] != -1) {
				continue;
			}
			stp[tox][toy] = std::max(map[tox][toy], nows + 1);
			q.push({tox, toy, stp[tox][toy]});
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		std::cerr << stp[i][j] << " \n"[j == m];
	// 	}
	// }

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = std::max(ans, stp[i][j]);
		}
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}