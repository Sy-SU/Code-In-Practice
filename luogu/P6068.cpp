#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	if (n < 6) {
		std::cout << -1 << '\n';
		return;
	}

	int ans = n;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (i >= 6) {
				ans = std::min(ans, i);
			}
			if (n / i >= 6) {
				ans = std::min(ans, n / i);
			}
		}
	}

	std::cout << n / ans << '\n';
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