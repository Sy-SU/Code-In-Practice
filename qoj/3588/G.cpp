#include <bits/stdc++.h>

using i64 = long long;

struct Point {
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

struct Snake {
	int len;
	char dir;
	std::deque<Point> body;

	Snake(int r, int c) {
		len = 1;
		dir = 'U';
		Point head = {r, c};
		body.push_back(head);
	}

	void mov(char d, bool eat, std::vector<std::vector<int>> &vis) {
		auto [hdx, hdy] = body.front();
		Point newhead = {0, 0};
		if (d == 'U') {
			newhead = {hdx - 1, hdy};
		} else if (d == 'D') {
			newhead = {hdx + 1, hdy};
		} else if (d == 'L') {
			newhead = {hdx, hdy - 1};
		} else if (d == 'R') {
			newhead = {hdx, hdy + 1};
		}
		body.push_front(newhead);
		vis[newhead.x][newhead.y] = 1;
		if (!eat) {
			auto [bkx, bky] = body.back();
			vis[bkx][bky] = 0;
			body.pop_back();
		}
	}

	void print(int n, int m) {
		std::vector<std::vector<char>> map(n + 1, std::vector<char>(m + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				map[i][j] = '0';
			}
		}

		for (auto bd : body) {
			auto [x, y] = bd;
			map[x][y] = 'X';
		}

		auto [x, y] = body.front();
		map[x][y] = 'H';

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				std::cerr << map[i][j];
			}
			std::cerr << '\n';
		}
	}
};

void solve() {
	int n, m, r, c;
	std::cin >> n >> m >> r >> c;

	std::vector<std::vector<int>> map(n + 1, std::vector<int>(m + 1));
	map[r][c] = 1;

	Snake snk = Snake(r, c);

	for (int round = 1; round < n * m - 1; round++) {
		int destx, desty;
		std::cin >> destx >> desty;

		snk.print(n, m);

		
	}
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