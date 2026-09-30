#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		int lo = 0, hi = 0;
		for (int j = 1; j <= n; j++) {
			lo += a[j] < a[i];
			hi += a[j] > a[i];
		}

		int a1 = std::min(lo, hi), a2 = std::max(lo, hi);

		ans = std::min(ans, a2);
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