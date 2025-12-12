#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i] >> b[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] == b[i - 1]) {
			ans += (a[i] % 2 == a[i - 1] % 2 ? a[i] - a[i - 1] : a[i] - a[i - 1] - 1);
		} else {
			ans += (a[i] % 2 != a[i - 1] % 2 ? a[i] - a[i - 1] : a[i] - a[i - 1] - 1);
		}
	}

	ans += m - a[n];

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