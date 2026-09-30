#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int k;
	std::cin >> k;

	std::vector<i64> c(k + 1);
	for (int i = 1; i <= k; i++) {
		std::cin >> c[i];
	}

	std::sort(c.begin() + 1, c.end(), std::greater<i64>());

	if (c[1] >= 3) {
		std::cout << "YES" << '\n';
		return;
	}

	if (k == 1) {
		std::cout << "NO" << '\n';
		return;
	}

	if (c[2] >= 2) {
		std::cout << "YES" << '\n';
		return;
	}

	std::cout << "NO" << '\n';
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