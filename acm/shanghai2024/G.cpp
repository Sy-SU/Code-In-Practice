#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1), b(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	std::sort(c.begin() + 1, c.end());

	i64 lo = -2e18, hi = 2e18;
	i64 ans = -4e18;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&](i64 x) -> bool {
			std::vector<int> pre, suf;
			for (int i = 1; i <= n; i++) {
				if (a[i] >= 0) {
					// a[i] * c[j] + b[i] >= x + 1
					int l = 1, r = n, f = n + 1;
					while (l <= r) {
						int m = (l + r) / 2;
						if (a[i] * c[m] + b[i] >= x + 1) {
							r = m - 1;
							f = m;
						} else {
							l = m + 1;
						}
					}
					suf.push_back(f);
				} else {
					int l = 1, r = n, f = 0;
					while (l <= r) {
						int m = (l + r) / 2;
						if (a[i] * c[m] + b[i] >= x + 1) {
							l = m + 1;
							f = m;
						} else {
							r = m - 1;
						}
					}
					pre.push_back(f);
				}
			}

			// for (auto p : pre) {
			// 	std::cerr << "p" << p << '\n';
			// }
			// for (auto s : suf) {
			// 	std::cerr << "s" << s << '\n';
			// }

			std::sort(pre.begin(), pre.end());
			std::sort(suf.begin(), suf.end(), std::greater<int>());

			int cnt = 0; // >= x + 1 的个数

			int now = 0;
			for (auto p : pre) {
				if (p > now) {
 					now++, cnt++;
				}
			}

			now = n + 1;
			for (auto s : suf) {
				if (s < now) {
					now--, cnt++;
				}
			}

			// std::cerr << x << " " << cnt << "\n";

			return cnt < (n + 1) / 2;
		};

		if (check(mid)) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}