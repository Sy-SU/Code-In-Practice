#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	if (n % 2 == 0) {
		for (int i = 1; i <= n; i += 2) {
			std::cout << i + 1 << " " << i << " " << i << " " << i + 1 << " " << i << " " << i + 1 << " " << i + 1 << " " << i << " ";
		}
		std::cout << '\n';
	} else {
		std::cout << "1 1 2 1 2 3 1 3 2 2 3 3 ";
		for (int i = 4; i <= n; i += 2) {
			std::cout << i + 1 << " " << i << " " << i << " " << i + 1 << " " << i << " " << i + 1 << " " << i + 1 << " " << i << " ";
		}
		std::cout << '\n';
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