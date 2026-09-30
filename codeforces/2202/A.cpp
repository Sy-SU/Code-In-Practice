#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x, y;
	std::cin >> x >> y;

	// if (x >= 2 * y && (x - 2 * y) % 3 == 0) {
	// 	std::cout << "YES" << '\n';
	// } else {
	// 	std::cout << "NO" << '\n';
	// }

	if ((x - 2 * y) % 3 != 0) {
		std::cout << "NO" << '\n';
		return;
	}
	if (y < 0) {
		if (x + 4 * y >= 0) {
			std::cout << "YES" << '\n';
		} else {
			std::cout << "NO" << '\n';
		}
	} else {
		if (x >= 2 * y) {
			std::cout << "YES" << '\n';
		} else {
			std::cout << "NO" << '\n';
		}
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