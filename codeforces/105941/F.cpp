#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, -1, 0, 1};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<char>> map(n + 1, std::vector<char>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
		}
	}

	// auto copy = map;

	std::vector<std::pair<int, int>> setS, setT;
	std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));

	std::queue<std::pair<int, int>> q;
	q.push({1, 1});
	vis[1][1] = 1;
	while (!q.empty()) {
		auto [x, y] = q.front();
		bool isadd = 0;
		for (int d = 0; d < 4; d++) {
			int dx = dirx[d], dy = diry[d];
			int tox = x + dx, toy = y + dy;
			if (tox <= 0 || tox >= n + 1 || toy <= 0 || toy >= m + 1 || map[tox][toy] == '#') {
				isadd = 1;
			}
		}
		if (isadd) {
			setS.push_back({x, y});		
			// std::cerr << "visS" << x << " " << y << '\n';
			// copy[x][y] = 'X';
		}


		q.pop();

		for (int d = 0; d < 4; d++) {
			int dx = dirx[d], dy = diry[d];
			int tox = x + dx, toy = y + dy;
			if (tox <= 0 || tox >= n + 1 || toy <= 0 || toy >= m + 1) {
				continue;
			}
			if (vis[tox][toy]) {
				continue;
			}
			if (map[tox][toy] == '#') {
				continue;
			}

			vis[tox][toy] = 1;
			q.push({tox, toy});
		}
	}

	q.push({n, m});
	vis[n][m] = 1;
	while (!q.empty()) {
		auto [x, y] = q.front();
		bool isadd = 0;
		for (int d = 0; d < 4; d++) {
			int dx = dirx[d], dy = diry[d];
			int tox = x + dx, toy = y + dy;
			if (tox <= 0 || tox >= n + 1 || toy <= 0 || toy >= m + 1 || map[tox][toy] == '#') {
				isadd = 1;
			}
		}
		if (isadd) {
			setT.push_back({x, y});	
			// copy[x][y] = 'X';	
			// std::cerr << "visT" << x << " " << y << '\n';
		}

		q.pop();

		for (int d = 0; d < 4; d++) {
			int dx = dirx[d], dy = diry[d];
			int tox = x + dx, toy = y + dy;
			if (tox <= 0 || tox >= n + 1 || toy <= 0 || toy >= m + 1) {
				continue;
			}
			if (vis[tox][toy]) {
				continue;
			}
			if (map[tox][toy] == '#') {
				continue;
			}

			vis[tox][toy] = 1;
			q.push({tox, toy});
		}
	}

	int ans = 1e9;
	for (const auto &[sx, sy] : setS) {
		for (const auto &[tx, ty] : setT) {
			ans = std::min(ans, std::abs(sx - tx) + std::abs(sy - ty));
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		std::cerr << copy[i][j];
	// 	}
	// 	std::cerr << '\n';
	// }
	std::cout << std::max(0, ans - 1) << '\n';
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