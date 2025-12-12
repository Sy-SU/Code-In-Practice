#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, x;
	std::cin >> n >> x;

	std::vector<i64> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> d(n + 2);
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] < 0) {
			d[std::min(n, i + x - 1) + 1] += d[i], ans -= d[i], d[i] = 0;
		}
	}

	std::cout << "YES\n" << ans << '\n';
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