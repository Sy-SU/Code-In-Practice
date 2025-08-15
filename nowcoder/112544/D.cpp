#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int x, p;
	std::cin >> x >> p;

	if (p % x == 0) {
		std::cout << p / x * 2 - 1 << '\n';
	} else {
		std::cout << p * 2 - (p / x) * 2 << '\n';
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