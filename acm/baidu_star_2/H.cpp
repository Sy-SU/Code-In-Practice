#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 x, y;
	std::cin >> n >> x >> y;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::map<i64, i64> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	i64 maxcnt = 0; // 出现次数最多的
	for (auto [num, ct] : cnt) {
		maxcnt = std::max(maxcnt, ct);
	}

	i64 ans = y * (n - maxcnt);

	// ans = std::min(ans, n * y);

	i64 pre = 0;
	for (auto [num, ct] : cnt) {
		pre += ct;
		ans = std::min(ans, num * x + (n - pre) * y);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}