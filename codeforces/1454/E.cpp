#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> edge(n + 1);
	for (int i = 1; i <= n; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
	}

	std::vector<int> circle(n + 1), fa(n + 1), vis(n + 1);
	bool tag = 0;
	int sta = -1;
	auto find_circle = [&](auto &&self, int u, int f) -> void {
		if (tag) {
			return;
		}
		fa[u] = f;
		if (vis[u]) {
			tag = 1;
			sta = u;
			return;
		}
		vis[u] = 1;
		for (auto v : edge[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
		}
	};

	find_circle(find_circle, 1, 0);

	// std::cerr << "sta = " << sta << '\n';
	int now = sta;
	while (1) {
		circle[now] = 1;
		// std::cerr << "on c" << now << '\n';
		now = fa[now];
		if (now == sta) {
			break;
		}
	}

	std::vector<int> sz(n + 1);

	auto dfs = [&](auto &&self, int u, int f, int r) -> void {
		sz[r]++;
		for (auto v : edge[u]) {
			if (v == f || circle[v]) {
				continue;
			}
			self(self, v, u, r);
		}
	};

	for (int i = 1; i <= n; i++) {
		if (!circle[i]) {
			continue;
		}
		dfs(dfs, i, 0, i);
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << sz[i] << " \n"[i == n];
	// }

	i64 ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		ans += sz[i] * 1ll * (sz[i] - 1) / 2;
		ans += sz[i] * 1ll * sum * 2;
		sum += sz[i];
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