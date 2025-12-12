#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 2), b(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> preamax(n + 2), preamin(n + 2, 1e9), sufbmax(n + 2), sufbmin(n + 2, 1e9);
	for (int i = 1; i <= n; i++) {
		preamax[i] = std::max(preamax[i - 1], a[i]);
		preamin[i] = std::min(preamin[i - 1], a[i]);
	}

	for (int i = n; i >= 1; i--) {
		sufbmax[i] = std::max(sufbmax[i + 1], b[i]);
		sufbmin[i] = std::min(sufbmin[i + 1], b[i]);
	}

	std::vector<int> qmaxra(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		int lo = 1, hi = n, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (preamax[mid] <= i) {
				lo = mid + 1;
				ans = mid;
			} else {
				hi = mid - 1;
			}
		}

		qmaxra[i] = ans;
	}

	std::vector<int> qminrb(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		int lo = 1, hi = n, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (sufbmax[mid] <= i) {
				hi = mid - 1;
				ans = mid;
			} else {
				lo = mid + 1;
			}
		}

		qminrb[i] = ans;
	}

	i64 cnt = 0;
	for (int l = 1; l <= 2 * n; l++) {
		int lo = l, hi = 2 * n, r = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			auto check = [&](int cr) -> bool {
				int lo = 1, hi = n, up = -1;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;

					if (preamax[mid] <= cr && preamin[mid] >= l) {
						up = mid;
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}

				lo = 1, hi = n;
				int down = n + 1;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;

					if (sufbmax[mid] <= cr && sufbmin[mid] >= l) {
						down = mid;
						hi = mid - 1;
					} else {
						lo = mid + 1;
					}
				}

				return up >= down;
			};

			if (check(mid)) {
				hi = mid - 1;
				r = mid;
			} else {
				lo = mid + 1;
			}
		}
		if (r != -1) {
			cnt += 1ll * (2 * n - r + 1);
		}
	}

	std::cout << cnt << '\n';
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