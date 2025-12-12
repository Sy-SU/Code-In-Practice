#include <bits/stdc++.h>

using i64 = long long;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::string s;
	std::cin >> s;

	int mod = s.size();

	std::vector<std::vector<char>> map(n + 2, std::vector<char>(m + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
		}
	}

	std::vector<int> cost(4, 1);

	for (auto ch : s) {
		if (ch == 'U') {
			cost[0] = 0;
		} else if (ch == 'L') {
			cost[1] = 0;
		} else if (ch == 'D') {
			cost[2] = 0;
		} else {
			cost[3] = 0;
		}
	}

	std::vector<std::vector<int>> dist(n + 2, std::vector<int>(n + 2, 1e9));
	dist[1][1] = 0;

	std::vector<std::vector<int>> vis(n + 2, std::vector<int>(n + 2, 0));
	vis[1][1] = 1;

	std::queue<std::pair<int, int>> q;
	q.push({1, 1});

	std::vector<std::vector<char>> lst(n + 2, std::vector<char>(n + 2));

	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int tox = dx[d] + x, toy = dy[d] + y;
			if (tox < 1 || tox > n || toy < 1 || toy > m || map[tox][toy] == '#') {
				continue;
			}

			if (dist[tox][toy] > dist[x][y] + cost[d]) {
				dist[tox][toy] = dist[x][y] + cost[d];
				if (d == 0) {
					lst[tox][toy] = 'U';
				} else if (d == 1) {
					lst[tox][toy] = 'L';
				} else if (d == 2) {
					lst[tox][toy] = 'D';
				} else {
					lst[tox][toy] = 'R';
				}
				// std::cerr << "lst" << tox << " " << toy << " = " << lst[tox][toy] << '\n';
			}
			if (!vis[tox][toy]) {
				vis[tox][toy] = 1;
				q.push({tox, toy});
			}
		}
	}

	std::cout << dist[n][m] << '\n';

	std::string op;
	int nowx = n, nowy = m;
	while (nowx != 1 || nowy != 1) {
		// std::cerr << nowx << " " << nowy << " " << lst[nowx][nowy] << '\n';
		op += lst[nowx][nowy];
		if (lst[nowx][nowy] == 'U') {
			nowx++;
		} else if (lst[nowx][nowy] == 'L') {
			nowy++;
		} else if (lst[nowx][nowy] == 'D') {
			nowx--;
		} else {
			nowy--;
		}
	}
	std::reverse(op.begin(), op.end());
	std::cerr << op << '\n';

	std::vector<std::vector<int>> fir(mod + 1, std::vector<int>(4, 1e9));
	for (int i = mod - 1; i >= 0; i--) {
		int chv = 0;
		if (s[i] == 'L') {
			chv = 1;
		} else if (s[i] == 'D') {
			chv = 2;
		} else if (s[i] == 'R') {
			chv = 3;
		}
		for (int v = 0; v < 4; v++) {
			if (chv == v) {
				fir[i][v] = i;
			} else {
				fir[i][v] = fir[i + 1][v];
			}
		}
	}
	for (int i = mod - 1; i >= 0; i--) {
		for (int v = 0; v < 4; v++) {
			if (fir[i][v] == 1e9) {
				fir[i][v] = fir[0][v] + mod;
			}
		}
	}

	// i64 ti = 0;
	// for (auto ch : op) {
	// 	int modt = ti % mod;
	// 	int chval = 0;
	// 	if (ch == 'L') {
	// 		chval = 1;
	// 	} else if (ch == 'D') {
	// 		chval = 2;
	// 	} else if (ch == 'R') {
	// 		chval = 3;
	// 	}

	// 	if (cost[chval] == 1) {
	// 		ti++;
	// 		continue;
	// 	}
	// 	// modt 往后第一个 ch 的位置
	// 	int next = fir[modt][chval];
	// 	ti += next - modt + 1;
	// }

	// std::cout << ti << '\n';

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}