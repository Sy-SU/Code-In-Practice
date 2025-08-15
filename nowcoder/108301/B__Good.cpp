#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<std::vector<char>> mat(n + 1, std::vector<char>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m;j++) {
			std::cin >> mat[i][j];
		}
	}

	// ed : {1, m}
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	mat[1][m] = '2';
	{
		std::queue<std::pair<int, int>> edq;
		edq.push({1, m});

		std::vector<std::vector<int>> vis(n + 1, std::vector<int>(m + 1));
		vis[1][m] = 1;
	
		while (!edq.empty()) {
			auto [nowx, nowy] = edq.front();
			edq.pop();
	
			for (int i = 0; i < 4; i++) {
				if (dx[i] == 0 && dy[i] == 1) {
					continue;
				}
	
				int tox = nowx + dx[i], toy = nowy + dy[i];
				if (tox <= 0 || tox >= n + 1 || toy <= 0 || toy >= m + 1) {
					continue;
				}
				if (vis[tox][toy]) {
					continue;
				}
				if (mat[tox][toy] == '1') {
					continue;
				}
	
				vis[tox][toy] = 1;
				mat[tox][toy] = '2';
				edq.push({tox, toy});
			}
		}
	}

	assert(mat[1][1] == '2');
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		std::cerr << mat[i][j];
	// 	}
	// 	std::cerr << '\n';
	// }
	// std::cerr << '\n';

	std::vector<std::pair<int, int>> zeros;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mat[i][j] == '0') {
				zeros.push_back({i, j});
			}
		}
	}

	std::sort(zeros.begin(), zeros.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
		return p1.second > p2.second;
	});

	std::vector<std::vector<int>> maxy(n + 1, std::vector<int>(m + 1));
	{
		std::vector<std::vector<int>> vis1(n + 1, std::vector<int>(m + 1));
	
		for (auto [stax, stay] : zeros) {
			if (vis1[stax][stay]) {
				continue;
			}
			vis1[stax][stay] = 1;
			maxy[stax][stay] = stay;
			std::queue<std::pair<int, int>> zq;
			zq.push({stax, stay});
			while (!zq.empty()) {
				auto [nowx, nowy] = zq.front();
				zq.pop();
				for (int i = 0; i < 4; i++) {
					if (dx[i] == 0 && dy[i] == 1) {
						continue;
					}
	
					int tox = nowx + dx[i], toy = nowy + dy[i];
					if (tox <= 0 || tox >= n + 1 || toy <= 0 || toy >= m + 1) {
						continue;
					}
	
					if (vis1[tox][toy]) {
						continue;
					}
					if (mat[tox][toy] != '0') {
						continue;
					}
	
					zq.push({tox, toy});
	
					vis1[tox][toy] = 1;
					maxy[tox][toy] = std::max(maxy[tox][toy], maxy[nowx][nowy]);
				}	
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		if (mat[i][j] != '0') {
	// 			std::cerr << 'X';
	// 		} else {
	// 			std::cerr << maxy[i][j];
	// 		}
	// 	}
	// 	std::cerr << '\n';
	// }

	{
		std::queue<std::pair<int, int>> qq;
		qq.push({1, 1});
		std::vector<std::vector<int>> visq(n + 1, std::vector<int>(m + 1));
		visq[1][1] = 1;

		while (!qq.empty()) {
			auto [nowx, nowy] = qq.front();
			qq.pop();

			if (nowy < m && mat[nowx][nowy + 1] == '0' && maxy[nowx][nowy + 1] - nowy >= k) {
				std::cout << "Yes" << '\n';
				return;
			}

			for (int i = 0; i < 4; i++) {
				if (dx[i] == 0 && dy[i] == -1) {
					continue;
				}
				int tox = nowx + dx[i], toy = nowy + dy[i];
				if (tox <= 0 || tox >= n + 1 || toy <= 0 || toy >= m + 1) {
					continue;
				}

				if (visq[tox][toy]) {
					continue;
				}
				if (mat[tox][toy] != '2') {
					continue;
				}

				qq.push({tox, toy});
				visq[tox][toy] = 1;
			}
		}
	}
	
	std::cout << "No" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}