#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> ls(n + 1), rs(n + 1), fa(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> ls[i] >> rs[i];
		if (ls[i]) {
			fa[ls[i]] = i;
		}
		if (rs[i]) {
			fa[rs[i]] = i;
		}
	}

	int maxd = 70;
	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(maxd + 1, 1e14));

	dp[0][0] = 0, dp[0][1] = 1;
	for (int d = 2; d <= maxd; d++) {
		dp[0][d] = dp[0][d - 1] + dp[0][d - 2] + 1;
	}

	std::vector<int> sz(n + 1);

	auto dfs = [&](auto &&self, int u) -> void {
		sz[u] = 1;
		// ls[u], rs[u]
		if (ls[u]) {
			self(self, ls[u]);
			sz[u] += sz[ls[u]];
		}
		if (rs[u]) {
			self(self, rs[u]);
			sz[u] += sz[rs[u]];
		}

		dp[u][0] = sz[u];
		// std::cerr << "dp" << u << " " << 0 << "<-" << dp[u][0] << '\n';
		for (int d = 1; d <= maxd; d++) {
			// std::cerr << ls[u] << " " << rs[u] << " " << d << '\n';
			// std::cerr << dp[ls[u]][d - 1] << " " << dp[rs[u]][d - 1] << " " << dp[ls[u]][d] << " " << dp[rs[u]][d] << '\n';
			if (d == 1) {
				// std::cerr << u << " " << d << " " << dp[ls[u]][d - 1] << " " << dp[rs[u]][d - 1] << '\n';
				dp[u][d] = std::min({100000000000000 * 1ll, dp[ls[u]][d - 1] + dp[rs[u]][d - 1]});
			} else {
				dp[u][d] = std::min({100000000000000 * 1ll, dp[ls[u]][d - 1] + dp[rs[u]][d - 2], dp[ls[u]][d - 2] + dp[rs[u]][d - 1], dp[ls[u]][d - 1] + dp[rs[u]][d - 1]});
			}
			// std::cerr << "dp" << u << " " << d << "<-" << dp[u][d] << '\n';
		}
	};

	dfs(dfs, 1);

	i64 ans = 1e18;
	for (int d = 0; d <= maxd; d++) {
		// std::cerr << d << " " << dp[1][d] << '\n';
		ans = std::min(ans, dp[1][d]);
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