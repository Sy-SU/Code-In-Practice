#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) {
			std::swap(a[i], b[i]);
		}
	}

	std::vector<std::pair<i64, i64>> vec(n + 1);
	for (int i = 1; i <= n; i++) {
		vec[i] = {a[i], b[i]};
	}

	std::sort(vec.begin() + 1, vec.end());

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += std::abs(vec[i].first - vec[i].second);
	}

	i64 add = 1e18, sufbmin = 1e18;
	for (int i = n; i >= 1; i--) {
		add = std::min(add, 2 * std::max(0ll, (sufbmin - vec[i].first)));
		sufbmin = std::min(sufbmin, vec[i].second);
	}

	ans += add;
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