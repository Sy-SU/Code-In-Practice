#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 p, q;
	std::cin >> p >> q;

	if (q <= p || 3 * p - 2 * q < 0) {
		std::cout << "Alice" << '\n';
	} else {
		std::cout << "Bob" << "\n";
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