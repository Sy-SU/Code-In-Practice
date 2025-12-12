#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<i64>> v(n + 2, std::vector<i64>(m + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> v[i][j];
		}
	}

	std::vector<std::vector<i64>> up(n + 2, std::vector<i64>(m + 2));
	std::vector<std::vector<i64>> down(n + 2, std::vector<i64>(m + 2));

	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= m; j += 3) {
			i64 sum = v[i][j] + v[i][j - 1] + v[i - 1][j] + v[i][j + 1];
			up[i][j] = (sum ? sum : up[i - 1][j]);
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int j = 2; j <= m; j += 3) {
			i64 sum = v[i][j] + v[i][j - 1] + v[i + 1][j] + v[i][j + 1];
			down[i][j] = (sum ? sum : down[i + 1][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		i64 ans = 0;
		for (int j = 1; j <= m; j++) {
			ans += v[i - 1][j] + v[i][j] + v[i + 1][j];
			ans += (i >= 3 ? up[i - 2][j] : 0) + (i <= n - 2 ? down[i + 2][j] : 0);
		}
		std::cout << ans << " \n"[i == n];
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