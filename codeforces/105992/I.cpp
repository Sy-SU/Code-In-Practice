#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
	}

	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(n + 1));
	std::vector<int> son(n + 1);

	auto dfs = [&](auto &&self, int u, int fa) -> void {
		son[u] = 1;
		for (auto v : edge[u]) {
			if (v == fa) {
				continue;
			}
			self(self, v, u);
			son[u] += son[v];
		}


		// dp[u][0..son[u]]
		// 卷积算贡献
		std::vector<i64> cnt(son[u] + 1);
		cnt[0] = 1;
		int maxid = 0;
		for (auto v : edge[u]) {
			if (v == fa) {
				continue;
			}
			std::vector<i64> tmp(maxid + son[v] + 1);
			for (int i = 0; i <= maxid; i++) {
				for (int j = 0; j <= son[v]; j++) {
					tmp[i + j] = (tmp[i + j] + cnt[i] * dp[v][j]) % mod;
					}
			}
			maxid += son[v];
			for (int i = 0; i <= maxid; i++) {
				cnt[i] = tmp[i];
			}
		}

		// if (son[u] == 1) {
		// 	maxid = 0;
		// 	cnt[0] = 1;
		// }

		// std::cerr << maxid << '\n';
		// for (int i = 0; i <= maxid; i++) {
		// 	std::cerr << cnt[i] << " \n"[i == maxid];
		// }

		if (son[u] == 1) {
			dp[u][0] = (a[u] != 0);
			dp[u][1] = (a[u] == 1);
			// std::cerr << u << " " << dp[u][0] << " " << dp[u][1] << '\n';
		} else {
			for (int i = 0; i <= maxid; i++) {
				if (i == a[u] - 1) {
					// u 是诚实的
					dp[u][i + 1] = (dp[u][i + 1] + cnt[i]) % mod;
				}
				if (i != a[u]) {
					dp[u][i] = (dp[u][i] + cnt[i]) % mod;
				}
			}			
		}


	};

	dfs(dfs, 1, 0);

	i64 ans = 0;
	for (int x = 0; x <= n; x++) {
		ans = (ans + dp[1][x]) % mod;
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