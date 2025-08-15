#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int x, y;
	std::cin >> x >> y;
	
	if (y <= x + 1 && (x + 1 - y) % 9 == 0) {
		std::cout << "Yes" << '\n';
	} else {
		std::cout << "No" << '\n';
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