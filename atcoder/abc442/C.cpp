#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> cnt(n + 1, n - 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		cnt[u]--, cnt[v]--;
	}

	for (int i = 1; i <= n; i++) {
		std::cout << cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6 << " \n"[i == n];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}