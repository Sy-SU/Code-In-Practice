#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 500 + 10;

int n, m;

char map[N][N];
int fa[N * N];

int find(int x){
	if (fa[x] == x) {
		return fa[x];
	}
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[find(x)] = find(y);
}

bool query(int x, int y) {
	return find(x) == find(y);
}

int tran(int x, int y) {
	return y + (x - 1) * m;
}

std::vector<std::pair<int, int>> vec[N * N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
	std::cin >> n >> m;

	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			map[i][j] = 'x';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
			fa[tran(i, j)] = tran(i, j);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '0') {
				continue;
			}
			if (map[i + 1][j] == '1') {
				merge(tran(i, j), tran(i + 1, j));
			}
			if (map[i][j + 1] == '1') {
				merge(tran(i, j), tran(i, j + 1));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// std::cout << (map[i][j] == '1' ? find(tran(i, j)) : 0) << " \n"[j == m];
			if (map[i][j] == '1') {
				vec[find(tran(i, j))].push_back({i, j});
			}
		}	
	}

	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (vec[tran(i, j)].size() == 0) {
				continue;
			}
			std::set<std::pair<int, int>> need;
			for (const auto &[x, y] : vec[tran(i, j)]) {
				for (int d = 0; d < 4; d++) {
					if (map[x + dx[d]][y + dy[d]] == '0') {
						need.insert({x + dx[d], y + dy[d]});
					}
				}
			}
			ans = std::min(ans, (int)need.size());
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