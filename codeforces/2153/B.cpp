#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x, y, z;
	std::cin >> x >> y >> z;

	for (int i = 1; i <= 32; i++) {
		int a = x % 2, b = y % 2, c = z % 2;
		x /= 2, y /= 2, z /= 2;

		if (a + b + c == 2) {
			std::cout << "NO" << '\n';
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