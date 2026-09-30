#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 p, q;
	std::cin >> p >> q;

	for (i64 n = 1; n <= 10000; n++) {
		i64 m = (p + 2 * q - n) / (2 * n + 1);
		if (m <= 0) {
			continue;
		}
		// std::cerr << "nm" << n << " " << m << '\n';
		// std::cerr << "check " <<n * m * 2 + n + m << " " << p + 2 * q << " " << q << " " <<  n * m << '\n';
		if (n * m * 2 + n + m != p + 2 * q) {
			continue;
		}
		if (p < std::abs(n - m)) {
			continue;
		}
		std::cout << n << " " << m << '\n';
		return;
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