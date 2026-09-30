#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 x, y;
	std::cin >> n >> x >> y;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i] / x * y;
	}

	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, a[i] + sum - a[i] / x * y);
	}

	std::cout << ans << '\n';
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