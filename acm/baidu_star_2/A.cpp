#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> edge(n + 1);
	std::vector<int> d(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
		d[u]++, d[v]++;
	}

	std::vector<i64> nextleaf(n + 1); // 下一层的叶子节点数量
	std::vector<int> fat(n + 1), fafat(n + 1);

	i64 del = 0;

	auto dfs = [&](auto &&self, int u, int fa) -> void {
		fat[u] = fa, fafat[u] = fat[fa];
		for (auto v : edge[u]) {
			if (v == fa) {
				continue;
			}
			self(self, v, u);
			nextleaf[u] += d[v] == 1;
		}
	};

	auto dfs1 = [&](auto &&self, int u, int fa) -> void {
		if (d[u] == 1) {
			del += nextleaf[fafat[u]];
		}
		for (auto v : edge[u]) {
			if (v == fa) {
				continue;
			}
			self(self, v, u);
		}
	};

	int r = 1;
	for (int i = 1; i <= n; i++) {
		if (d[i] != 1) {
			r = i;
		}
	}

	dfs(dfs, r, 0);

	dfs1(dfs1, r, 0);

	i64 ans = n * 1ll * (n - 1) / 2 - (n - 1) - del;
	
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}