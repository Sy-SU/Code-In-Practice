#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (i % 2 ? a[i] : -a[i]);
	}

	i64 ans = sum + (n - 1 - (n % 2 ? 0 : 1));


	i64 bonus = 0;

	i64 min = 1e18;
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			min = std::min(min, 2 * a[i] + i);
		} else {
			bonus = std::max(bonus, 2 * a[i] + i - min);
		}
	}

	min = 1e18;
	for (int i = n; i >= 1; i--) {
		if (i % 2) {
			min = std::min(min, 2 * a[i] - i);
		} else {
			bonus = std::max(bonus, 2 * a[i] - i - min);
		}
	}

	ans = std::max(ans, sum + bonus);
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