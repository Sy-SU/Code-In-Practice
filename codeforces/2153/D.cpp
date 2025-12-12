#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	std::vector<i64> b = a;
	std::sort(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
		ans += std::abs(b[i] - b[n / 2]);
	}

	for (int r = 0; r < 10; r++) {
		std::vector<i64> c;
		for (int i = r; i < r + n; i++) {
			c.push_back(a[i % n]);
		}

		// for (auto cc : c) {
		// 	std::cerr << cc << " ";
		// }
		// std::cerr << '\n';

		std::vector<i64> dp(n);
		for (int i = 1; i < n; i++) {
			if (i == 1) {
				dp[i] = std::abs(c[i - 1] - c[i]);
			} else if (i == 2) {
				std::vector<i64> t;
				t.push_back(c[0]), t.push_back(c[1]), t.push_back(c[2]);
				std::sort(t.begin(), t.end());

				for (int j = 0; j < 3; j++) {
					dp[i] += std::abs(t[j] - t[1]);
				}
			} else {
				dp[i] = dp[i - 2] + std::abs(c[i - 1] - c[i]);

				std::vector<i64> t;
				t.push_back(c[i]), t.push_back(c[i - 1]), t.push_back(c[i - 2]);
				std::sort(t.begin(), t.end());

				if (i > 4) {
					i64 tdp = dp[i - 3];
					for (int j = 0; j < 3; j++) {
						tdp += std::abs(t[j] - t[1]);
					}
					dp[i] = std::min(dp[i], tdp);
				}
			}
			// std::cerr << "dp" << i << "=" << dp[i] << "\n";
		}
		ans = std::min(ans, dp[n - 1]);
		// std::cerr << dp[n - 1] << '\n';
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