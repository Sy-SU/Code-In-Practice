#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

char map[5][5];

void solve() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			std::cin >> map[i][j];
		}
	}

	int cnt = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cnt += map[i][j] == 'X';
		}
	}
	if (cnt <= 1) {
		std::cout << "Yes" << '\n';
		return;
	}

	auto check = [&]() -> bool {
		for (int i = 1; i <= 3; i++) {
			bool isok = 1;
			for (int j = 1; j <= 3; j++) {
				if (map[i][j] != 'X') {
					isok = 0;
				}
			}
			if (isok) {
				return 1;
			}
		}

		for (int j = 1; j <= 3; j++) {
			bool isok = 1;
			for (int i = 1; i <= 3; i++) {
				if (map[i][j] != 'X') {
					isok = 0;
				}
			}
			if (isok) {
				return 1;
			}
		}

		if (map[1][1] == 'X' && map[2][2] == 'X' && map[3][3] == 'X') {
			return 1;
		}

		if (map[1][3] == 'X' && map[2][2] == 'X' && map[3][1] == 'X') {
			return 1;
		}

		return 0;
	};

	if (cnt == 2) {
		// if (map[1][2] == 'X' && map[2][3] == 'X' && map[2][2] == 'O' && map[1][3] == 'O') {
		// 	std::cout << "No" << '\n';
		// 	return;
		// }

		// if (map[1][2] == 'X' && map[2][1] == 'X' && map[2][2] == 'O' && map[1][1] == 'O') {
		// 	std::cout << "No" << '\n';
		// 	return;
		// }

		// if (map[3][2] == 'X' && map[2][3] == 'X' && map[2][2] == 'O' && map[3][3] == 'O') {
		// 	std::cout << "No" << '\n';
		// 	return;
		// }

		// if (map[3][2] == 'X' && map[2][1] == 'X' && map[2][2] == 'O' && map[3][1] == 'O') {
		// 	std::cout << "No" << '\n';
		// 	return;
		// }

		std::cout << "Yes" << '\n';
	}

	if (cnt == 3) {
		std::pair<int, int> point[3];
		int idx = 0;

		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (map[i][j] == 'G') {
					map[i][j] = 'X';
					point[idx++] = {i, j};
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			map[point[i].first][point[i].second] = 'O';

			if (check()) {
				std::cout << "Yes" << '\n';
				return;
			}

			map[point[i].first][point[i].second] = 'X';
		}
		std::cout << "No" << '\n';
	}

	if (cnt == 4) {
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (map[i][j] == 'G') {
					map[i][j] = 'X';
				}
			}
		}	

		if (check()) {
			std::cout << "Yes" << '\n';
		} else {
			std::cout << "No" << '\n';
		}
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