#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::pair<int, int>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		int l, r;
		std::cin >> l >> r;

		a[i] = {l, r};
	}

	std::sort(a.begin(), a.end());

	int ans = 0;
	std::priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		if (!pq.empty()) {
			ans = std::max(ans, std::max(0, std::min(a[i].second, pq.top()) - a[i].first + 1));
		}
		pq.push(a[i].second);
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