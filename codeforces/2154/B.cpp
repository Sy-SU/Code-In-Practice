#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1), pm(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		pm[i] = std::max(pm[i - 1], a[i]);
	}

	a[0] = 1e12;

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			ans += std::max(0ll, a[i] - a[i - 1] + 1);
			a[i] -= std::max(0ll, a[i] - a[i - 1] + 1);
		} else {
			a[i] = std::max(pm[i - 1], a[i]);
			if (a[i] == a[i - 1]) {
				ans++;
			}
		}
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