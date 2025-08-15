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
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	std::map<i64, i64> cnt;
	i64 ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += cnt[pre[i] - i];
		cnt[pre[i] - i]++;
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