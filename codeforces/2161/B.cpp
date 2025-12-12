#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<char>> map(n + 1, std::vector<char>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> map[i][j];
		}
	}

	int x = -1, y = -1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == '#') {
				x = i, y = j;
				cnt++;
			}
		}
	}

	if (x == -1 && y == -1) {
		std::cout << "YES" << '\n';
		return;
	}

	bool isok = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j - i != y - x && j - i != y - x + 1) {
				if (map[i][j] == '#') {
					isok = 0;
				}
			}
		}
	}
	if (isok) {
		std::cout << "YES" << '\n';
		return;
	}

	isok = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j - i != y - x && j - i != y - x - 1) {
				if (map[i][j] == '#') {
					isok = 0;
				}
			}
		}
	}
	if (isok) {
		std::cout << "YES" << '\n';
		return;
	}

	isok = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i + j != x + y && i + j != x + y + 1) {
				if (map[i][j] == '#') {
					isok = 0;
				}
			}
		}
	}
	if (isok) {
		std::cout << "YES" << '\n';
		return;
	}

	isok = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i + j != x + y && i + j != x + y - 1) {
				if (map[i][j] == '#') {
					isok = 0;
				}
			}
		}
	}
	if (isok) {
		std::cout << "YES" << '\n';
		return;
	}

	if (cnt == 4) {
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (map[i][j] == map[i][j + 1] && map[i][j + 1] == map[i + 1][j] && map[i + 1][j] == map[i + 1][j + 1] && map[i][j] == '#') {
					std::cout << "YES" << '\n';
					return;
				}
			}
		}
	}

	std::cout << "NO" << '\n';
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