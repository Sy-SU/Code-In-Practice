#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> pre(n + 2);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	pre[n + 1] = pre[n];

	i64 sum = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}
	ans = sum;

	std::vector<i64> maxsuf(n + 2, -1e18);
	for (i64 i = n; i >= 1; i--) {
		maxsuf[i] = std::max(maxsuf[i + 1], i + i * i - pre[i]);
	}

	for (i64 l = 1; l <= n; l++) {
		// r : l ~ n
		i64 best = pre[l - 1] + l - l * l + maxsuf[l];
		ans = std::max(ans, best + sum);
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