#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 x, y, k;
	std::cin >> x >> y >> k;

	if (y == 1) {
		std::cout << -1 << '\n';
		return;
	}

	i64 ans = k;
	for (i64 i = 1; i <= x; i++) {
		ans = ans + (ans - 1) / (y - 1);
		if (ans > 1e12) {
			std::cout << -1 << '\n';
			return;
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