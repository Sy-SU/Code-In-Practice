#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::cout << n * 2 - 1 << '\n';
	for (int i = 1; i <= n; i++) {
		if (i < n) {
			std::cout << i << " " << 1 << " " << i << '\n';
			std::cout << i << " " << i + 1 << " " << n << '\n';
		} else {
			std::cout << n << " " << 1 << " " << n << '\n';
		}
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