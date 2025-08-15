#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> premin(n + 1), min(n + 1);
	min[0] = 1e9;
	for (int i = 1; i <= n; i++) {
		min[i] = std::min(min[i - 1], a[i]);
		premin[i] = premin[i - 1] + min[i];
	}

	std::vector<i64> del(n + 1);
	for (int i = 1; i < n; i++) {
		del[i] = a[i] - a[i + 1];
	}

	std::vector<i64> mindel(n + 1);
	mindel[0] = 1e9;
	for (int i = 1; i <= n; i++) {
		mindel[i] = std::min(mindel[i - 1], del[i]);
	}

	i64 ans = premin[n];
	for (int j = n; j >= 2; j--) {
		// j
		if (mindel[j - 2] <= 0) {
			ans = std::min(ans, premin[j - 1]);
		} else {
			if (mindel[j - 2] >= 2 * n) {
				ans = std::min(ans, premin[j - 1] + a[j]);
			} else {
				ans = std::min(ans, premin[j - 1] + mindel[j - 2]);
			}
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