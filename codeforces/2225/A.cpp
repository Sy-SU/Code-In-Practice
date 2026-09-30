#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 x, y;
	std::cin >> x >> y;

	if (y / x == 2) {
		std::cout << "NO" << '\n';
	} else {
		std::cout << "YES" << '\n';
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