#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	i64 sum = 0;	
	std::vector<i64> dp(n + 1);	
	for (int j = 1; j <= n; j++) {
		dp[j] = 1;
		for (int k = j - 2; k <= j - 1; k++) {
			if (k < 1) {
				continue;
			}
			if (p[k] > p[j]) {
				dp[j] = std::max(dp[j], dp[k] + 1);
			}
		}
		sum += dp[j];
	}

	i64 ans = 0;
	for (int i = 1; i <= n - 2; i++) {
		ans += sum;
		if (p[i] > p[i + 1] && p[i] > p[i + 2]) {
			sum -= (n - i + 1);
		} else if (p[i] > p[i + 2] && p[i + 1] < p[i + 2]) {
			sum -= (n - i + 1);
		} else if (p[i] < p[i + 2] && p[i + 1] > p[i + 2]) {
			sum -= 1;
		} else if (p[i] < p[i + 1] && p[i] > p[i + 2]) {
			sum -= 1;
		}
	}
	ans += 2 + (p[n - 1] > p[n] ? 2 : 1);
	std::cout << ans << '\n';

	// i64 ans1 = 0;
	// std::vector<int> dp1(n + 1);
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = i; j <= n; j++) {
	// 		dp1[j] = 1;
	// 		for (int k = j - 2; k <= j - 1; k++) {
	// 			if (k < i) {
	// 				continue;
	// 			}
	// 			if (p[k] > p[j]) {
	// 				dp1[j] = std::max(dp1[j], dp1[k] + 1);
	// 			}
	// 		}
	// 		ans1 += dp1[j];
	// 	}
	// }
	// std::cerr << ans1 << '\n';
	// assert(ans1 == ans);
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