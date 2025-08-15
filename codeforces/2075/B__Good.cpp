#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	// if (k == 1) {
		i64 ans = 0;

		i64 tmpans = 0;
		for (int i = 2; i <= n; i++) {
			tmpans = std::max(tmpans, a[i]);
		}
		ans = std::max(ans, tmpans + a[1]);

		tmpans = 0;
		for (int i = 1; i < n; i++) {
			tmpans = std::max(tmpans, a[i]);
		}
		ans = std::max(ans, tmpans + a[n]);

		std::cout << ans << '\n';

	// }
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