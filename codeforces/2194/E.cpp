#include <bits/stdc++.h>

using i64 = long long;

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1, -1e18));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}

	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(m + 1, -1e18));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = a[i][j];
				continue;
			}
			dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
		}
	}

	std::vector<std::vector<std::pair<int, int>>> path(n + m + 1);
	path[n + m].push_back({n, m});
	for (int ind = n + m - 1; ind >= 2; ind--) {
		// std::cerr << "ind = " << ind << "\n";
		std::set<std::pair<int, int>> tmp;
		for (auto [x, y] : path[ind + 1]) {
			// x - 1, y x, y - 1
			// std::cerr << "vis" << x << " " << y << '\n';
			// std::cerr << dp[x - 1][y] << " " << dp[x][y - 1] << '\n';
			if (dp[x - 1][y] > dp[x][y - 1]) {
				tmp.insert({x - 1, y});
			} else if (dp[x - 1][y] < dp[x][y - 1]) {
				tmp.insert({x, y - 1});
			} else {
				tmp.insert({x - 1, y}), tmp.insert({x, y - 1});
			}
		}

		for (auto pt : tmp) {
			// std::cerr << "p" << ind << "ins" << pt.first << " " << pt.second << '\n';
			path[ind].push_back(pt);
		}
	}

	std::vector<std::pair<int, int>> v;
	i64 maxd = -1e18;
	for (int ind = 2; ind <= n + m; ind++) {
		// std::cerr << "ind = " << ind << '\n';
		if (path[ind].size() >= 2) {
			continue;
		}
		auto [x, y] = path[ind][0];
		// std::cerr << x << " " << y << " " << a[x][y] << '\n';
		// ans = std::min(ans, dp[n][m] - 2 * a[x][y]);
		maxd = std::max(maxd, a[x][y]);
	}

	i64 cans = -1e18;
	for (int ind = 2; ind <= n + m; ind++) {
		// std::cerr << "ind = " << ind << '\n';
		if (path[ind].size() >= 2) {
			continue;
		}
		auto [x, y] = path[ind][0];
		// std::cerr << x << " " << y << " " << a[x][y] << '\n';
		cans = std::min(cans, dp[n][m] - 2 * a[x][y]);
		if (maxd == a[x][y]) {
			v.push_back({x, y});
		}
	}
	
	std::shuffle(v.begin(), v.end(), rnd);

	i64 ans = 1e18;
	for (int vi = 0; vi < std::min(100, (int)v.size()); vi++) {
		auto b = a;
		auto [x, y] = v[vi];
		b[x][y] = -b[x][y];

		std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(m + 1, -1e18));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 && j == 1) {
					dp[i][j] = b[i][j];
					continue;
				}
				dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]) + b[i][j];
			}
		}

		ans = std::min(ans, dp[n][m]);
	}

	std::cout << std::max(ans, cans) << '\n';
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