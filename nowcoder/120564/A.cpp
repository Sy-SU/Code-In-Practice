#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int less = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			less += a[j] <= a[i];
		}
		if (less * 1.0 / (n - 1) >= 0.8) {
			ans += a[i];
		}
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}