#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 c;
	std::cin >> n >> c;

	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	i64 tans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) {
			tans = 1e18;
			break;
		}
		tans += a[i] - b[i];
	}

	i64 ans = c;
	std::sort(a.begin() + 1, a.end());
	std::sort(b.begin() + 1, b.end());

	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) {
			ans = 1e18;
			break;
		}
		ans += a[i] - b[i];
	}

	ans = std::min(ans, tans);

	if (ans >= 1e16) {
		ans = -1;
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