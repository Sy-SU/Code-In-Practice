#include <bits/stdc++.h>

using i64 = long long;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

struct Node {
	i64 dist;
	int x, y;
	bool operator > (Node n) const {
		return dist > n.dist;
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::string s;
	std::cin >> s;

	int mod = s.size();

	std::map<int, int> vis;
	for (auto ch : s) {
		if (ch == 'L') {
			vis[1] = 1;
		} else if (ch == 'D') {
			vis[2] = 1;
		} else if (ch == 'R') {
			vis[3] = 1;
		} else {
			vis[0] = 1;
		}
	}

	std::vector<std::vector<char>> map(n + 2, std::vector<char>(m + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
		}
	}

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

	std::vector<std::vector<i64>> dist(n + 1, std::vector<i64>(m + 1, 1e18));
	dist[1][1] = 0;

	std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
	pq.push({0, 1, 1});

	constexpr i64 MOD = 1e12;

	while (!pq.empty()) {
		auto [nowd, nowx, nowy] = pq.top();
		pq.pop();

		if (dist[nowx][nowy] < nowd) {
			continue;
		}

		for (int d = 0; d < 4; d++) {
			int tox = nowx + dx[d];
			int toy = nowy + dy[d];

			if (tox < 1 || tox > n || toy < 1 || toy > m || map[tox][toy] == '#') {
				continue;
			}

			i64 w = MOD + 1;
			if (vis[d]) {
				w = fir[(nowd % MOD) % mod][d] - ((nowd % MOD) % mod) + 1;
			}

			if (dist[tox][toy] > dist[nowx][nowy] + w) {
				dist[tox][toy] = dist[nowx][nowy] + w;
				pq.push({dist[tox][toy], tox, toy});
			}
		}
	}

	i64 ansd = dist[n][m];
	std::cout << ansd / MOD << " " << ansd % MOD << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}