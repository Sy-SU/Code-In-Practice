#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;

	int del = (a - 1) - (std::abs(b - c) + std::abs(c - 1));

	if (del < 0) {
		std::cout << 1 << '\n';
	} else if (del > 0) {
		std::cout << 2 << '\n';
	} else {
		std::cout << 3 << '\n';
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