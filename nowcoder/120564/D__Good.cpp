#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 c, a, b;
	std::cin >> c >> a >> b;

	i64 min = 1e18;
	for (i64 x = 0; x <= c; x++) {
		for (i64 y = 0; y <= c; y++) {
			if (x * a + y * b == c) {
				min = std::min(min, std::max(x, y));
			}
		}
	}
	for (i64 x = 0; x <= c; x++) {
		for (i64 y = 0; y <= c; y++) {
			if (x * a + y * b == c) {
				if (min == std::max(x, y)) {
					std::cout << "Yes" << '\n';
					std::cout << x << " " << y << '\n';
					return;
				}
			}
		}
	}
	std::cout << "No" << '\n';
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