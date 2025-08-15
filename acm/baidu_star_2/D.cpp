#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	if (n % 2) {
		for (int i = 1; i <= n; i++) {
			std::cout << i << " \n"[i == n];
		}
	} else {
		for (int i = 1; i <= n; i += 2) {
			std::cout << i + 1 << " " << i << " \n"[i == n - 1];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}