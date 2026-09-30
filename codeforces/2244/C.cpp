#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, x, y;
	std::cin >> n >> x >> y;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	int g = std::gcd(x, y);

	std::vector<int> ans;
	ans.push_back(0);

	std::vector<std::vector<int>> v(g + 1);
	for (int i = 1; i <= n; i++) {
		int m = (i - 1) % g + 1;
		v[m].push_back(p[i]);
	}

	for (int i = 1; i <= g; i++) {
		std::sort(v[i].begin(), v[i].end());
	}

	for (int i = 1; i <= n; i++) {
		int m = (i - 1) % g + 1;
		ans.push_back(v[m][(i - 1) / g]);
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << ans[i] << " \n"[i == n];
	// }

	for (int i = 1; i <= n; i++) {
		if (ans[i] != i) {
			std::cout << "NO" << "\n";
			return;
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