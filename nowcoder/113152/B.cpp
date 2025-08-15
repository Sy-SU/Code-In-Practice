#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int x, y;
	std::cin >> x >> y;

	int g = std::__gcd(x, y);

	if (x > y) {
		std::swap(x, y);
	}

	if (g + x > y) {
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