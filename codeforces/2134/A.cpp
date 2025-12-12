#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, a, b;
	std::cin >> n >> a >> b;

	if (b % 2 == n % 2) {
		if (a >= b) {
			if (a % 2 == n % 2) {
				std::cout << "YES" << '\n';
			} else {
				std::cout << "NO" << '\n';
			}
		} else {
			std::cout << "YES" << '\n';
		}
	} else {
		std::cout << "NO" << '\n';
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