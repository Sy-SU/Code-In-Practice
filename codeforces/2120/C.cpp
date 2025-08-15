#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n;
	i64 m;
	std::cin >> n >> m;

	if (m < n || m > (n + 1) * n / 2) {
		std::cout << -1 << '\n';
		return;
	}

	for (int base = 1; base <= n; base++) {
		i64 tmp = (base + 1) * base / 2 + (n - base) * base;
		if (n - base >= m - tmp) {
			std::cout << base + m - tmp << '\n';

			for (int i = 1; i <= n; i++) {
				if (i != base) {
					std::cout << i << " " << base << '\n';
				}
			}
			
			return;
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