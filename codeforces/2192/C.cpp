#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 h, k;
	std::cin >> n >> h >> k;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}

	i64 t = (n + k) * (h / sum);
	h %= sum;
	if (h == 0) {
		t -= k;
		std::cout << t << '\n';
		return;
	}

	i64 nd = 1e18;

	std::vector<i64> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	int lo = 1, hi = n, bd = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (pre[mid] >= h) {
			hi = mid - 1;
			bd = mid;
		} else {
			lo = mid + 1;
		}
	}
	// std::cerr << h << " " << t << '\n';
	assert(bd != -1);

	nd = bd;

	for (int i = 1; i <= bd - 1; i++) {
		// pre[i - 1] + maxa
		if (pre[i - 1] + a[bd] >= h) {
			nd = std::min(nd, i * 1ll);
		} else {
			int l = i + 1, r = bd, best = -1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (pre[m] + a[bd] - a[i] >= h) {
					r = m - 1;
					best = m;
				} else {
					l = m + 1;
				}
			}
			if (best != -1) {
				nd = std::min(nd, best * 1ll);
			}
		}
	}

	if (bd == n) {
		std::cout << t + nd << '\n';
		return;
	}

	i64 maxa = 0;
	for (int i = bd + 1; i <= n; i++) {
		maxa = std::max(maxa, a[i]);
	}

	for (int i = 1; i <= bd; i++) {
		// pre[i - 1] + maxa
		if (pre[i - 1] + maxa >= h) {
			nd = std::min(nd, i * 1ll);
		} else {
			int l = i + 1, r = bd, best = -1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (pre[m] + maxa - a[i] >= h) {
					r = m - 1;
					best = m;
				} else {
					l = m + 1;
				}
			}
			if (best != -1) {
				nd = std::min(nd, best * 1ll);
			}
		}
	}

	// std::cerr << nd << '\n';

	std::cout << t + nd << '\n';
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