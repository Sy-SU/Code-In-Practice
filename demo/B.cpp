#include <bits/stdc++.h>
 
using i64 = long long;
 
constexpr double eps = 1e-6;
 
void solve() {
	int n;
	std::cin >> n;
 
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> gval(n + 1), tran(n + 1);
	std::vector<int> preg;
	for (int i = 1; i <= n; i++) {
		gval[i].push_back(a[i]);
		for (auto pg : preg) {
			// 上一轮的 gval
			int ng = std::gcd(pg, a[i]);
			if (gval[i].back() != ng) {
				gval[i].push_back(ng);
			}
			tran[i].push_back((int)gval[i].size() - 1);
			// tran[i][j] 表示从 i - 1 的第 j 组 gcd 相同的 a[i] 被合并到 i 的第 tran[i][j] 组
		}
		preg = gval[i];
	}
 
	double lo = 0, hi = 1e6 + 10;
	double ans = -1;
	for (int iter = 1; iter <= 40; iter++) {
		double mid = (lo + hi) / 2;
 
		auto check = [&](double m) -> bool {
			std::vector<double> dp(n + 1, -1e18);
			dp[0] = 0;
			std::vector<double> now, next; // maxdp
			for (int i = 1; i <= n; i++) {
				next.assign(gval[i].size(), -1e18);

				for (int j = 0; j < (int)gval[i - 1].size(); j++) {
					int to = tran[i][j];
					next[to] = std::max(next[to], now[j]);
				}

				next[0] = std::max(next[0], dp[i - 1]);

				std::swap(now, next);

				for (int j = 0; j < (int)gval[i].size(); j++) {
					dp[i] = std::max(dp[i], now[j] + gval[i][j] - m);
				}

			}
 
			return dp[n] >= 0;
		};
 
		if (check(mid)) {
			lo = mid;
			ans = mid;
		} else {
			hi = mid;
		}
	}
 
	std::cout << std::fixed << std::setprecision(12) << ans << '\n';
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
