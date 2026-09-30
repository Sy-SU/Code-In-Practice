#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int q;
	std::cin >> q;

	int v = 0;
	int x = 0;

	for (int i = 1; i <= q; i++) {
		int a;
		std::cin >> a;

		if (a == 1) {
			v++;
		} else if (a == 2) {
			v = std::max(0, v - 1);
		} else {
			x = 1 - x;
		}

		if (x && v >= 3) {
			std::cout << "Yes" << '\n';
		} else {
			std::cout << "No" << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}