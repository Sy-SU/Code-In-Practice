#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 a, b, x, y;
	std::cin >> a >> b >> x >> y;

	if (a == x && b == y) {
		std::cout << "Yes" << '\n';
		return;
	}

	if (a == x) {
		if ((b | y) == y) {
			std::cout << "Yes" << '\n';
		} else {
			std::cout << "No" << '\n';
		}
		return;
	}

	if (b == y) {
		if ((a | x) == a) {
			std::cout << "Yes" << '\n';
		} else {
			std::cout << "No" << '\n';
		}
		return;
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