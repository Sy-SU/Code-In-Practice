#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 x, y;
	std::cin >> x >> y;

	for (i64 k = 1; k <= 1000000; k++) {
		if ((x + k) + (y + k) == ((x + k) ^ (y + k))) {
			std::cout << k << '\n';
			// return;
		}
	}
	std::cout << -1 << '\n';
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