#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> adj(n + 1);
	std::vector<int> son(n + 1);
	for (int i = 2; i <= n; i++) {
		int p;
		std::cin >> p;

		adj[p].push_back(i);
		son[p]++;
	}

	std::vector<int> dp(n + 1), len(n + 1);
	auto dfs = [&](auto &&self, int u, int f) -> void {
		dp[u] = 1;

		std::vector<int> lens;
		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}

			self(self, v, u);
			dp[u] += dp[v];
			len[u] = std::max(len[u], len[v] + 1);
			lens.push_back(len[v] + 1);
		}

		std::sort(lens.begin(), lens.end(), std::greater<int>());

		if (son[u] > 1) {
			dp[u] += lens[1];
		}
	};

	dfs(dfs, 1, 0);

	// for (int i = 1; i <= n; i++) std::cerr << len[i] << " \n"[i == n];

	std::cout << dp[1] << '\n';
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