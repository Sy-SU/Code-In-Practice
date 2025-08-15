#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<char>> map(n + 1, std::vector<char>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '0') {
				continue;
			}
			bool isok = 0;
			bool tmpok = 1;
			for (int ii = 1; ii < i; ii++) {
				if (map[ii][j] == '0') {
					tmpok = 0;
					break;
				}
			}
			isok |= tmpok;

			tmpok = 1;
			for (int jj = 1; jj < j; jj++) {
				if (map[i][jj] == '0') {
					tmpok = 0;
					break;
				}
			}
			isok |= tmpok;

			if (isok == 0) {
				std::cout << "NO" << '\n';
				return;
			}
		}
	}
	std::cout << "YES" << '\n';
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