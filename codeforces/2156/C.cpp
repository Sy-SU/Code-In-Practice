#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> cnt(4 * n + 1);
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	std::vector<int> pre(4 * n + 1);
	for (int i = 1; i <= 4 * n; i++) {
		pre[i] = pre[i - 1] + cnt[i];
	}

	int ans = 0;
	for (int g = 1; g <= n; g++) {
		int del = 0;
		for (int i = 2; i < 4; i++) {
			del += cnt[i * g];
		}
		if (pre[g - 1] + pre[4 * g - 1] - pre[g] - del <= k) {
			ans = g;
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