#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<std::pair<i64, i64>> pos(n + 1);
	for (int i = 1; i <= n; i++) {
		i64 x = a[i] + b[i], y = a[i] - b[i];
		pos[i] = {x, y};
	}

	i64 ans = 1e18;

	std::sort(pos.begin() + 1, pos.end());
	for (int i = 2; i <= n; i++) {
		ans = std::min(ans, pos[i].first - pos[i - 1].first);
	}

	std::sort(pos.begin() + 1, pos.end(), [](std::pair<i64, i64> p1, std::pair<i64, i64> p2) {
		return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
	});
	for (int i = 2; i <= n; i++) {
		ans = std::min(ans, pos[i].second - pos[i - 1].second);
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