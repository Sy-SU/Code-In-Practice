#include <bits/stdc++.h>

using i64 = long long;
#define int long long

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 lo = 0, hi = 1e18;
	// lo = hi = 8;
	i64 ans = -1;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&](i64 x) -> bool {
			auto a1 = a; 
			i64 sum = 0, cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (sum >= x && cnt < k) {
					sum = 0;
					a1[i] = -1;
					cnt++;
					continue;
				}
				sum += a[i];
			}

			auto a2 = a; 
			sum = 0, cnt = 0;
			for (int i = 2; i <= n; i++) {
				if (sum >= x && cnt < k) {
					sum = 0;
					a2[i] = -1;
					cnt++;
					continue;
				}
				sum += a[i];
			}

			i64 minans = 0;
			i64 tmpans = 1e18, tmpsum = 0;
			int wa = 0;
			for (int i = 1; i <= n; i++) {
				if (a1[i] == -1) {
					wa++;
					tmpans = std::min(tmpans, tmpsum);
					tmpsum = 0;
				} else {
					tmpsum += a1[i];
				}
			}
			if (tmpsum != 0) {
				tmpans = std::min(tmpans, tmpsum);
			}
			// std::cerr << wa << " " << k << '\n';
			if (wa == k) {
				minans = std::max(minans, tmpans);
			}

			tmpans = 1e18, tmpsum = 0, wa = 1;
			a2[1] = -1;
			for (int i = 2; i <= n; i++) {
				if (a2[i] == -1) {
					wa++;
					tmpans = std::min(tmpans, tmpsum);
					tmpsum = 0;
				} else {
					tmpsum += a2[i];
				}
			}
			if (tmpsum != 0) {
				tmpans = std::min(tmpans, tmpsum);
			}
			// std::cerr << wa << " " << k << " " <<tmpans << " " << x << '\n';
			if (wa == k) {
				minans = std::max(minans, tmpans);
			}

			// for (const auto & num : a1) {
			// 	std::cerr << num << " ";
			// }
			// std::cerr << '\n';
			// for (const auto & num : a2) {
			// 	std::cerr << num << " ";
			// }
			// std::cerr << '\n';

			return minans >= x;
		};

		if (check(mid)) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}

	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}