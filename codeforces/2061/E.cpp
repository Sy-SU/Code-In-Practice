#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 10;

i64 dp[2][N];

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<i64> a(n + 1, 0), b(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}

	std::vector<std::pair<i64, int>> vec;
	for (int bit = 0; bit < (1 << m); bit++) {
		i64 andb = 1073741823;
		int sumk = 0, idx = 1;

		int num = bit;
		while (num) {
			if (num % 2) {
				andb &= b[idx];
				sumk++;
			}
			num /= 2, idx++;
		}
		vec.push_back({andb, sumk});
	}

	// for (const auto &[db, mk] : vec) {
	// 	std::cerr << db << " " << mk << "\n";
	// }

	for (int j = 0; j <= k; j++) {
		dp[0][j] = dp[1][j] = 1e18;
	}	
	

	// dp[0][0] = 0;
	int l = -1e9, r = 1e9;
	for (int i = 1; i <= n; i++) {
		l = std::max(0, k - n * m - m + i);
		r = std::min(k, i * m);
		for (int cost = l; cost <= r; cost++) {
			dp[i & 1][cost] = 1e18;
			for (int idx = 0; idx < (int)vec.size(); idx++) {
				if (cost - vec[idx].second >= 0) {
					if (i == 1) {
						dp[i & 1][cost] = std::min(dp[i & 1][cost], (a[i] & vec[idx].first));				
					} else {
						dp[i & 1][cost] = std::min(dp[i & 1][cost], dp[!(i & 1)][cost - vec[idx].second] + (a[i] & vec[idx].first));				
					}
				}
			}
		}
	}

	i64 minans = 1e18;
	for (int cost = 0; cost <= k; cost++) {
		minans = std::min(minans, dp[n & 1][cost]);
	}
	std::cout << minans << '\n';
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