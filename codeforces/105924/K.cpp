#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> c(n + 1, std::vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> c[i][j];
		}
	}

	std::vector<int> max(m + 1);
	for (int j = 1; j <= m; j++) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i][j] == c[1][j]) {
				cnt++;
			} else {
				break;
			}
		}
		max[c[1][j]] = std::max(max[c[1][j]], cnt);
	}

	int ans = n * m;
	for (int j = 1; j <= m; j++) {
		ans -= max[j];
		// std::cerr << "max" << j << " = " << max[j] << '\n';
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}