#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	if (k == n * n - 1) {
		std::cout << "NO" << '\n';
		return;
	}

	std::cout << "YES" << '\n';

	int fail = n * n - k;

	int cnt = 0;

	std::vector<std::vector<char>> map(n + 2, std::vector<char>(n + 2, 'X'));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cnt < k) {
				if (k <= n) {
					map[i][j] = (i == 1 ? 'L' : 'U');
				} else {
					map[i][j] = (i == 1 ? 'R' : 'U');
				}
							} else {
				if (i != n) {
					map[i][j] = 'D';
				} else {
					if (j == 1 || cnt == k) {
						map[i][j] = 'R';
					} else {
						map[i][j] = 'L';
					}
				}
			}
			cnt++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << map[i][j];
		}
		std::cout << '\n';
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