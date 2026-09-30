#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, m, a, b;
	std::cin >> n >> m >> a >> b;

	a = (a - 1) % n + 1, b = (b - 1) % m + 1;

	bool ans = 0;	
	if (std::gcd(n, m) <= 2) {
		ans = 1; //充分
	}
	if (std::gcd(n, a) > 1 || std::gcd(m, b) > 1) {
		ans = 0; // 必要条件
	}

	std::cout << (ans ? "YES" : "NO") << '\n';

	std::vector<std::vector<int>> map1(n + 1, std::vector<int>(m + 1));
	int x = 1, y = 1;
	for (int i = 1; i <= 10000; i++) {
		map1[x][y] = 1;
		x = (x + a - 1) % n + 1;

		map1[x][y] = 1;
		y = (y + b - 1) % m + 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cerr << map1[i][j] << " \n"[j == m];
		}
	}

	// std::vector<std::vector<int>> map2(n + 1, std::vector<int>(m + 1));
	// x = 1, y = 1;
	// for (int i = 1; i <= 10000; i++) {
	// 	map2[x][y] = 1;
	// 	y = (y + b - 1) % m + 1;

	// 	map2[x][y] = 1;
	// 	x = (x + a - 1) % n + 1;
	// }

	// std::cerr << "===\n";

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		std::cerr << map2[i][j] << " \n"[j == m];
	// 	}
	// }

	// bool isok = 0;

	// bool ps = 1;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		if (map1[i][j] == 0) {
	// 			ps = 0;
	// 		}
	// 	}
	// }
	// isok |= ps;

	// ps = 1;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		if (map2[i][j] == 0) {
	// 			ps = 0;
	// 		}
	// 	}
	// }
	// isok |= ps;

	// assert(isok == ans);
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