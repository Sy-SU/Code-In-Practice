#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	if (n % 2) {
		std::cout << n << " ";
		for (int i = 1; i < n; i++) {
			std::cout << i << " \n"[i == n - 1];
		}
	} else {
		std::cout << -1 << '\n';
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