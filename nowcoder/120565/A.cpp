#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> map(n + 1, std::vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				if (j == 1) {
					map[i][j] = 0;
				} else {
					map[i][j] = 1 - map[i][j - 1];
				}
			} else {
				map[i][j] = 1 - map[i - 1][j];
			}			
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) {
				std::cout << "\\";
			} else {
				std::cout << "/";
			}
		}
		std::cout << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}