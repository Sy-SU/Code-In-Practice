#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> a(n + 2, std::vector<int>(n + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = (j - 1) * n + i;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = std::max(ans, a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1]);
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