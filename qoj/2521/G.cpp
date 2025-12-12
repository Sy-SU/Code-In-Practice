#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	if (n == 1 || n == 2 || n == 4) {
		std::cout << -1 << '\n';
		return;
	}

	if (n % 3 == 2 || n % 3 == 0) {
		std::cout << n / 3 << '\n';
	} else {
		std::cout << n / 3 - 1 << '\n';
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