#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 x, y;
	std::cin >> x >> y;

	if (x > y) {
		std::swap(x, y);
	} else if (x == y) {
		std::cout << -1 << '\n';
		return;
	}

	i64 base = 1;
	while (base <= y) {
		base *= 2;
	}

	i64 k = base - y;
	std::cout << k << '\n';
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