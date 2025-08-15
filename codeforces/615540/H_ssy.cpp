#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

i64 qpow(i64 a, int b, int mod) {
	i64 res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

i64 inv(int x) {
	return qpow(x, mod - 2, mod);
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> edge(n + 1);
	std::vector<i64> p(n + 1);

	for (int i = 2; i <= n; i++) {
		int fa;
		i64 x, y;
		std::cin >> fa >> x >> y;

		edge[i].push_back(fa), edge[fa].push_back(i);
		p[i] = x * inv(y) % mod;
	}

	std::vector<i64> dp(n + 1), sz(n + 1), pdp(n + 1), sumpdp(n + 1);

	auto dfs1 = [&](auto &&self, int u, int fa) -> void {
		sz[u] = 1;
		for (const auto &v : edge[u]) {
			if (v == fa) {
				continue;
			}
			self(self, v, u);
			sz[u] += sz[v];

			sumpdp[u] = (sumpdp[u] + sumpdp[v]) % mod;
		}
		// dp[u] = p + (1 - p) * (pdp of the subtree of u except u)

		if (u == 1) {
			return;
		}

		dp[u] = inv(p[u]) * (p[u] + (1 - p[u] + mod) % mod * (1 + inv(sz[u]) % mod * sumpdp[u] % mod) % mod) % mod;
		
		pdp[u] = sz[u] * dp[u] % mod;

		sumpdp[u] = (sumpdp[u] + pdp[u]) % mod;
	};

	dfs1(dfs1, 1, 0);

	std::vector<i64> ans(n + 1);

	auto dfs2 = [&](auto &&self, int u, int fa) -> void {
		ans[u] += dp[u];
		ans[u] %= mod;
		// std::cerr << "ans" << u << " += " << dp[u] << '\n';
		for (const auto &v : edge[u]) {
			if (v == fa) {
				continue;
			}
			ans[v] += ans[u];
			ans[v] %= mod;
			// std::cerr << "ans" << v << " += " << ans[u] << '\n';
			self(self, v, u);
		}
	};

	dfs2(dfs2, 1, 0);

	for (int i = 2; i <= n; i++) {
		std::cout << ans[i] << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}