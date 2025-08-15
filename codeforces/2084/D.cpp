#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	for (int x = n; x >= 1; x--) {
		if (x <= k) {
			int cnt = (n - x) / k;
			if (cnt >= m) {
				for (int i = 1; i <= n; i++) {
					std::cout << ((i - 1) % k) << " \n"[i == n];
				}
				return;
			}
		} else {
			int cnt = n / x;
			if (cnt > m) {
				for (int i = 1; i <= n; i++) {
					std::cout << (i % x) << " \n"[i == n];
				}
				return;
			}
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