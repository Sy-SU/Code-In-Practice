#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, l, r, k;
	std::cin >> n >> l >> r >> k;

	if (n % 2) {
		std::cout << l << '\n';
		return;
	}

	if (n == 2) {
		std::cout << -1 << '\n';
		return;
	}

	i64 min = 1;
	while (min <= l) {
		min *= 2;
	}

	if (min > r) {
		std::cout << -1 << '\n';
		return;
	}

	if (k <= n - 2) {
		std::cout << l << '\n';
	} else {
		std::cout << min << '\n';
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