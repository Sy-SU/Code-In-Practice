#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1, 0));
	std::vector<i64> sumadd(n + m + 10, 0), sumdel(2 * n + 2 * m + 10, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
			sumadd[i + j] += a[i][j], sumdel[n + m + i - j] += a[i][j];
		}
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = std::max(ans, sumadd[i + j] + sumdel[n + m + i - j] - a[i][j]);
		}
	}
	std::cout << ans << '\n';
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