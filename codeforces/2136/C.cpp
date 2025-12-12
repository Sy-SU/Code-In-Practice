#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::map<std::pair<int, int>, int> pos;
	std::vector<int> cnt(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		cnt[a[i]]++;
		pos[{a[i], cnt[a[i]]}] = i;
		if (cnt[a[i]] >= a[i]) {
			// cnt[a[i]] - a[i] + 1
			dp[i] = std::max(dp[i], dp[pos[{a[i], cnt[a[i]] - a[i] + 1}] - 1] + a[i]);
		}
	}

	std::cout << dp[n] << '\n';
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