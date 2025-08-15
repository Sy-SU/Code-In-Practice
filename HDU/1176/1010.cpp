#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<double> p(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;

		p[i] = 1.0 - x * 1.0 / 1000;
	}

	std::vector<double> dp(n + 1);
	double mindp = 1e12;
	for (int i = n; i >= 1; i--) {
		// 第 i 分钟, p[i] 过, 1 - p[i] 不过
		dp[i] = p[i] * i + (1 - p[i]) * (mindp + 20);
		mindp = std::min(mindp, dp[i]);
 	}

	std::cout << std::fixed << std::setprecision(10) << mindp << '\n';
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