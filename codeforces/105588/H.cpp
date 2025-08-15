#include <bits/stdc++.h>

using i64 = long long;
using Point = std::pair<int, int>;

constexpr long double pi = 3.141592653589793;

void solve() {
	int k, n;
	std::cin >> n >> k;

	std::vector<Point> point(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> point[i].first >> point[i].second;
	}

	std::sort(point.begin() + 1, point.end(), [](Point p1, Point p2) {
		return atan2(p1.second, p1.first) < atan2(p2.second, p2.first);
	});

	if (k == n) {
		std::cout << std::fixed << std::setprecision(10) << 2 * pi << '\n';
		return;
	}

	std::vector<long double> angle;
	for (int i = 1; i <= n; i++) {
		angle.push_back(atan2(point[i].second, point[i].first));
	}
	for (int i = 0; i < n; i++) {
		angle.push_back(angle[i] + 2 * pi);
	}

	long double ans = 0;
	for (int i = 0; i < n; i++) {
		ans = std::max(ans, angle[i + k] - angle[i]);
	}
	std::cout << std::fixed << std::setprecision(10) << ans << '\n';

}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}