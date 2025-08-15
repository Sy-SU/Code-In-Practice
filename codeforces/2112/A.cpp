#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int a, x, y;
	std::cin >> a >> x >> y;

	if (x > y) {
		std::swap(x, y);
	}

	if (x < a && a < y) {
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