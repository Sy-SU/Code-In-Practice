#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 c;
	std::cin >> n >> c;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	std::sort(a.begin() + 1, a.end(), std::greater<i64>());
	for (int i = 1; i <= n; i++) {
		if (i <= (n + 1) / 2) {
			ans += a[i] - c;
		} else {
			if (a[i] >= c) {
				ans += a[i] - c;
			} else {
				break;
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