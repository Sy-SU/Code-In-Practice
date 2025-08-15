#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1), b(n + 1), c(n + 1), d(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] > d[i]) {
			ans += a[i] + (b[i] - d[i]);
		} else if (a[i] > c[i]) {
			ans += a[i] - c[i];
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