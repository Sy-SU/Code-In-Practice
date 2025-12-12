#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<i64> predp(n + 2, -1e18), sufdp(n + 2, -1e18);
	for (int i = 1; i <= n; i++) {
		predp[i] = std::max(a[i], predp[i - 1] + a[i]);
	}
	for (int i = n; i >= 1; i--) {
		sufdp[i] = std::max(a[i], sufdp[i + 1] + a[i]);
	}

	if (k % 2) {
		i64 ans = -1e18;
		for (int i = 1; i <= n; i++) {
			ans = std::max(ans, std::max(0ll, predp[i - 1]) + std::max(0ll, sufdp[i + 1]) + a[i] + b[i]);
		}
		std::cout << ans << '\n';
	} else {
		i64 ans = -1e18;
		for (int i = 1; i <= n; i++) {
			ans = std::max(ans, std::max(0ll, predp[i - 1]) + std::max(0ll, sufdp[i + 1]) + a[i]);
		}
		std::cout << ans << '\n';
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