#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, t;
	std::cin >> n >> t;

	std::vector<i64> h(n + 1), v(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> v[i];
	}

	std::vector<i64> ansv(n + 2);

	i64 max = 0, max2 = 0;
	for (int i = n; i >= 1; i--) {
		if (v[i] >= max) {
			max2 = max, max = v[i];
		} else if (v[i] >= max2) {
			max2 = v[i];
		}

		ansv[i] = max + max2;
	}

	i64 ans = 0;
	for (int i = 1; i <= t; i++) {
		i64 x;
		std::cin >> x;

		int lo = 1, hi = n, pos = n + 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (h[mid] < x) {
				pos = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		ans += ansv[pos];
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}