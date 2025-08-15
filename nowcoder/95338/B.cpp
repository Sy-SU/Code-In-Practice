#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

std::pair<i64, i64> vec[N][2];
i64 dp[N][2];

void solve() {
	int n;
	i64 c[2];
	std::cin >> n >> c[0] >> c[1];

	for (int i = 1; i <= n; i++) {
		std::cin >> vec[i][0].first >> vec[i][0].second;
		vec[i][1] = {vec[i][0].second, vec[i][0].first};
	}

	vec[n + 1][0] = vec[n + 1][1] = {1e12, 1e12};

	for (int i = 1; i <= n + 1; i++) {
		dp[i][0] = dp[i][1] = 1e16;
	}

	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[i][0].first >= vec[j][0].first && vec[i][0].second >= vec[j][0].second) {
				dp[i][0] = std::min(dp[i][0], dp[j][0] + (i - j - 1) * c[0]);
			}
			if (vec[i][0].first >= vec[j][1].first && vec[i][0].second >= vec[j][1].second) {
				dp[i][0] = std::min(dp[i][0], dp[j][1] + (i - j - 1) * c[0]);
			}

			if (vec[i][1].first >= vec[j][0].first && vec[i][1].second >= vec[j][0].second) {
				dp[i][1] = std::min(dp[i][1], dp[j][0] + (i - j - 1) * c[0] + c[1]);
			}
			if (vec[i][1].first >= vec[j][1].first && vec[i][1].second >= vec[j][1].second) {
				dp[i][1] = std::min(dp[i][1], dp[j][1] + (i - j - 1) * c[0] + c[1]);
			}
		}
	}

	std::cout << std::min(dp[n + 1][0], dp[n + 1][1]) << '\n';
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