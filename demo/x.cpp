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
 
	double lo = 0, hi = 1e5 + 10;
	double ans = -1;
	for (int iter = 1; iter <= 30; iter++) {
		double mid = (lo + hi) / 2;
 
		auto check = [&](double m) -> bool {
			std::vector<double> dp(n + 1, -1e18);
			dp[0] = 0;
			std::vector<std::pair<int, double>> node, next; // {sufgcd, maxdp}
			for (int i = 1; i <= n; i++) {
				next.clear();
				next.reserve(40);
				next.push_back({a[i], dp[i - 1]});
 
				for (auto &[g, maxdp] : node) {
				    int ng = std::__gcd(g, a[i]);
					if (!next.empty() && next.back().first == ng) {
						next.back().second = std::max(next.back().second, maxdp);
					} else {
						next.push_back({ng, maxdp});
					}
				}
 
				std::swap(node, next);
 
				double max = -1e18;
				for (auto &[g, maxdp] : node) {
					max = std::max(max, maxdp + g - m);
				}
				dp[i] = max;
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
