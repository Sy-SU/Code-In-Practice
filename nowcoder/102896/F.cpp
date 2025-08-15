#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e3 + 10;

struct NODE {
	int x, y;
	int dir, t;
};

bool vis[N][N][3];

void solve() {
	int n, m, h;
	std::cin >> n >> m >> h;

	std::vector<std::vector<char>> map(n + 2, std::vector<char>(m + 2, '0'));
	std::vector<std::vector<int>> hp(n + 2, std::vector<int>(m + 2, -1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
		}
	}

	// 0 上 1 左 2 右

	std::queue<NODE> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '*') {
				q.push({i, j, 0, 0});
			} else if (map[i][j] == '#') {
				hp[i][j] = h - 1;
			}
		}
	}

	while (!q.empty()) {
		auto &[x, y, d, t] = q.front();
		q.pop();

		vis[x][y][d] = 0;

		// std::cerr << x << " " << y << " " << d << " " << t << '\n';

		if (x < 1 || x > n || y < 1 || y > m) {
			continue;
		}

		if (d == 0) {
			if (map[x + 1][y] == '%') {
				std::cout << t + 1 << '\n';
				return;
			} else if (map[x + 1][y] == '.') {
				if (!vis[x + 1][y][0]) {
					vis[x + 1][y][0] = 1;
					q.push({x + 1, y, 0, t + 1});
				}
			} else if (hp[x + 1][y] < 0) {
				if (!vis[x + 1][y][0]) {
					vis[x + 1][y][0] = 1;
					q.push({x + 1, y, 0, t + 1});
				}
			} else {
				hp[x + 1][y]--;
				
				vis[x][y][0] = 1;
				q.push({x, y, 0, t + 1});

				if (map[x][y - 1] != '#') {
					q.push({x, y - 1, 1, t + 1});
					vis[x][y - 1][1] = 1;
				}

				if (map[x][y + 1] != '#') {
					q.push({x, y + 1, 2, t + 1});
				 	vis[x][y + 1][2] = 1; 
				}
			}
		} else if (d == 1) {
			if (map[x][y - 1] == '%') {
				std::cout << t + 1 << '\n';
				return;
			} else if (map[x + 1][y] == '.') {
				if (!vis[x + 1][y][0]) {
					vis[x + 1][y][0] = 1;
					q.push({x + 1, y, 0, t + 1});
				} 
			} else {
				if (map[x][y - 1] == '%') {
					std::cout << t + 1 << '\n';
					return;
				} else if (map[x][y - 1] == '.') {
					if (!vis[x][y - 1][1]) {
						vis[x][y - 1][1] = 1;
						q.push({x, y - 1, 1, t + 1});
					}
				}
			}
		} else {
			if (map[x][y + 1] == '%') {
				std::cout << t + 1 << '\n';
				return;
			} else if (map[x + 1][y] == '#') {
				if (!vis[x + 1][y][0]) {
					vis[x + 1][y][0] = 1;
					q.push({x + 1, y, 0, t + 1});
				} 
			} else {
				if (map[x][y + 1] == '%') {
					std::cout << t + 1 << '\n';
					return;
				} else if (map[x][y + 1] == '.') {
					if (!vis[x][y + 1][2]) {
						vis[x][y + 1][2] = 1;
						q.push({x, y + 1, 2, t + 1});
					}
				}
			}
			
		}
	}

	std::cout << -1 << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}