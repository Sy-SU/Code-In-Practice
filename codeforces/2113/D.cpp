#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	int lo = 0, hi = n;
	// lo = hi = 4;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int win) -> bool {
			// 1 ~ win // win + 1 ~ n
			// std::cerr << "check" << win << '\n';
			int minind = -1, maxind = -1;
			int minnum = 1e9, maxnum = 0;
			for (int i = 1; i <= win; i++) {
				if (a[i] < minnum) {
					minnum = a[i], minind = i;
				}
			}
			for (int i = win + 1; i <= n; i++) {
				if (a[i] > maxnum) {
					maxnum = a[i], maxind = i;
				}
			}

			bool isswap = 0;
			if (minind != -1 && maxind != -1 && a[minind] < a[maxind]) {
				isswap = 1;
				std::swap(a[minind], a[maxind]);
			}

			// std::cerr << minind << " " << maxind << '\n';

			int cnt = 0;
			int fsta = 1, fstb = 1;
			for (int i = 1; i <= n; i++) {
				if (a[fsta] > b[fstb]) {
					fsta++, cnt++;
				} else {
					fstb++;
				}
			}

			// std::cerr << cnt << " " << win << '\n';

			if (isswap) {
				std::swap(a[minind], a[maxind]);
			}

			return cnt >= win; 
 		};

		if (check(mid)) {
			// std::cerr << "ok" << mid << '\n';
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
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