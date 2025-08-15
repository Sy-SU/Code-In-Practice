#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}

	std::map<std::pair<int, int>, int> vis;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == std::min(i, j)) {
				ans++;
			} else {
				vis[{a[i][j], std::min(i, j)}]++;
			}
		}
	}

	std::map<int, int> visa;
	for (auto [p, _] : vis) {
		auto [aij, mn] = p;
		if (_ == 0) {
			continue;
		}
		visa[aij] = 1;
		if (vis[{mn, aij}]) {
			std::cout << ans + 2 << '\n';
			return;
		}
	}

	for (auto [p, _] : vis) {
		auto [aij, mn] = p;
		if (_ == 0) {
			continue;
		}
		if (visa[mn]) {
			std::cout << ans + 1 << '\n';
			return;
		}
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}