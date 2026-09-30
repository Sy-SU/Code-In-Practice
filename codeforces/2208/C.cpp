#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> c(n + 1), p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i] >> p[i];
	}

	double ans = 0;

	for (int i = n; i >= 1; i--) {
		if (ans * (1.0 - p[i] * 1.0 / 100) + c[i] >= ans) {
			ans = ans * (1.0 - p[i] * 1.0 / 100) + c[i];
		}
	}

	std::cout << std::fixed << std::setprecision(12) << ans << '\n';
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