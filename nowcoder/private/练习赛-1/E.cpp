#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
	int n;
	std::cin >> n;
 
	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
 
	std::vector<std::vector<std::pair<int, i64>>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		i64 w;
		std::cin >> u >> v >> w;
 
		edge[u].push_back({v, w}), edge[v].push_back({u, w});
	}
    
    int q;
    std::cin >> q;
	{
        int s, x;
        std::cin >> s >> x;
		std::vector<int> fat(n + 1, -1);
		std::vector<i64> d(n + 1);
		auto dfs1 = [&](auto &&self, int u, int fa) -> void {
			fat[u] = fa;
			for (const auto &[v, w] : edge[u]) {
				if (v == fa) {
					continue;
				}
				self(self, v, u);
				d[v] = w;
			}
		};
 
		dfs1(dfs1, s, -1);
 
		std::vector<i64> b = a;
 
		for (int i = 1; i <= n; i++) {
			a[i] -= 2 * d[i];
		}
 
		std::vector<int> onpath(n + 1);
		int now = x;
		while (now != -1) {
			onpath[now] = 1, a[now] += d[now];
			now = fat[now];
		}
 
		std::vector<i64> dp(n + 1, -1e15);
		auto dfs2 = [&](auto &&self, int u, int fa) -> void {
			dp[u] = a[u];
			for (const auto &[v, w] : edge[u]) {
				if (v == fa) {
					continue;
				}
				self(self, v, u);
				if (dp[v] > 0 || onpath[v]) {
					dp[u] += dp[v];
				}
			}
		};
 
		dfs2(dfs2, s, -1);
 
		std::cout << dp[s] << '\n';
 
		a = b;
	}
 
	
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