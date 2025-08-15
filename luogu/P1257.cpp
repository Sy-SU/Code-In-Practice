#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::pair<long double, long double>> vec;
	for (int i = 1; i <= n; i++) {
		long double x, y;
		std::cin >> x >> y;
		vec.push_back({x, y});
	}

	std::sort(vec.begin(), vec.end());

	long double ans = 1000000000000000;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// std::cerr << (vec[i].first - vec[j].first) * (vec[i].first - vec[j].first) + (vec[i].second - vec[j].second) * (vec[i].second - vec[j].second) << '\n';
			ans = std::min(ans, std::sqrt((vec[i].first - vec[j].first) * (vec[i].first - vec[j].first) + (vec[i].second - vec[j].second) * (vec[i].second - vec[j].second)));			
		}
	}
	std::cout << std::fixed << std::setprecision(4) << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}