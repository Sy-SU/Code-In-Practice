#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> map(n + 1, std::vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 1; j <= m; j++) {
				map[i][j] = j;
			}
			continue;
		}
		int sta = 1;
		for (int j = 1; j <= m; j++) {
			if (map[i - 1][j] == m * (i - 2) + 1) {
				sta = j;
				break;
			}
		}
		int num = m * (i - 1);
		if (map[i - 1][sta] % 2 != (num + 1) % 2) {
			sta++;
			if (sta == m + 1) {
				sta = 1;
			}
		}
		
		for (int j = sta; j <= m; j++) {
			map[i][j] = ++num;
		}
		for (int j = 1; j < sta; j++) {
			map[i][j] = ++num;
		}
	}

	std::cout << "Yes" << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cout << map[i][j] << " \n"[j == m];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}