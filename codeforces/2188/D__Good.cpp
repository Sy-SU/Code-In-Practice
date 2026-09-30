#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x, y;
	std::cin >> x >> y;

	if (x < y) {
		std::swap(x, y);
	}

	int ans = 1e9;
	std::vector<std::pair<int, int>> vec;
	for (int p = 1; p <= 10000; p++) {
		for (int q = 1; q <= 10000; q++) {
			if (p & q) {
				continue;
			}
			if (ans > std::abs(x - p) + std::abs(y - q)) {
				ans = std::abs(x - p) + std::abs(y - q);
				vec.clear();
				vec.push_back({p, q});
			} else if (ans == std::abs(x - p) + std::abs(y - q)) {
				vec.push_back({p, q});
			}
		}
	}

	std::cout << "x = " << x << " " << " y = " << y << '\n';
	// std::cout << "ans = " << ans << '\n';
	for (auto [p, q] : vec) {
		if (q == y || p == x) {
			std::cout << p << " " << q << '\n';
			std::cerr << "del = " << std::max(std::abs(p - x), std::abs(q - y)) << '\n';
			return;
		}
	}
	std::cout << "failed" << '\n';
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