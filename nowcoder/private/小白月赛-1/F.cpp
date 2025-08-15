#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

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

	std::vector<int> fa(n + 1), dep(n + 1), son(n + 1), sz(n + 1), top(n + 1), wei(n + 1); // wei(u) 表示 wei(u, p(u))

	auto dfs1 = [&](auto &&self, int u, int f) -> void {
		fa[u] = f, dep[u] = dep[f] + 1, sz[u] = 1;
		for (const auto &[v, w] : edge[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
			sz[u] += sz[v];
			if (sz[son[u]] < sz[v]) {
				son[u] = v;
			}

			wei[v] = w;
		}
	};

	dfs1(dfs1, 1, 0);

	auto dfs2 = [&](auto &&self, int u, int t) -> void {
		top[u] = t;
		if (son[u] == 0) {
			return;
		}
		self(self, son[u], t);
		for (const auto &[v, w] : edge[u]) {
			if (v == fa[u] || v == son[u]) {
				continue;
			}
			self(self, v, v);
		}
	};

	dfs2(dfs2, 1, 1);

	auto lca = [&](int u, int v) -> int {
		while (top[u] != top[v]) {
	        if (dep[top[u]] < dep[top[v]]){
	        	std::swap(u, v);
	        }
	        u = fa[top[u]];
	    }
	    return dep[u] < dep[v] ? u : v;
	};

	std::vector<i64> down(n + 1), sumdown(n + 1);

	auto dfs3 = [&](auto &&self, int u, int f) -> void {
		down[u] = a[u] - 2 * wei[u];
		for (const auto &[v, w] : edge[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
			down[u] += down[v], sumdown[u] += down[v];
		}
		down[u] = std::max(0ll, down[u]);
	};

	dfs3(dfs3, 1, 0);

	std::vector<i64> up(n + 1);

	auto dfs4 = [&](auto &&self, int u, int f) -> void {
		for (const auto &[v, w] : edge[u]) {
			if (v == f) {
				continue;
			}
			up[v] = std::max(0ll, a[u] + sumdown[u] + up[u] - down[v] - 2 * w);
			self(self, v, u);
		}
	};

	dfs4(dfs4, 1, 0);

	std::vector<i64> valnode(n + 1), valedge(n + 1), prenode(n + 1), preedge(n + 1);

	auto dfs5 = [&](auto &&self, int u, int f) -> void {
		prenode[u] = prenode[f] + (valnode[u] = a[u] + sumdown[u] + up[u]);
		preedge[u] = preedge[f] + (valedge[u] = down[u] + up[u] + wei[u]);
		for (const auto &[v, w] : edge[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
		}
	};

	dfs5(dfs5, 1, 0);

	int q;
	std::cin >> q;

	while (q--) {
		int s, x;
		std::cin >> s >> x;

		int l = lca(s, x);

		std::cout << (prenode[s] + prenode[x] - 2 * prenode[l] + valnode[l]) - (preedge[s] + preedge[x] - 2 * preedge[l]) << " \n"[q == 0];
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