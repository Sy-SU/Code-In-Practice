#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> pre(n + 1);
	pre[1] = a[1];
	for (int i = 2; i <= n; i++) {
		pre[i] = pre[i - 1] + std::max(a[i], -a[i]);
	}

	i64 sum = 0, ans = -1e18;
	for (int i = n; i >= 1; i--) {
		ans = std::max(ans, pre[i - 1] + sum);
		sum -= a[i];
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