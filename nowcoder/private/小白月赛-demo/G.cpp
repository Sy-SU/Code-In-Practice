#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> o = a;

	std::vector<std::vector<std::pair<int, i64>>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		i64 w;
		std::cin >> u >> v >> w;

		edge[u].push_back({v, w}), edge[v].push_back({u, w});
	}

	std::vector<int> fa(n + 1), dep(n + 1), son(n + 1), sz(n + 1), top(n + 1);
	std::vector<i64> d(n + 1);

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
			d[v] = w;
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

	for (int i = 1; i <= n; i++) {
		a[i] -= 2 * d[i];
	}

	std::vector<i64> dp(n + 1), bonus(n + 1);
	auto dfs3 = [&](auto &&self, int u, int f) -> void {
		dp[u] = a[u];
		for (const auto &[v, w] : edge[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
			dp[u] += std::max(0ll, dp[v]);
		}
		bonus[u] = std::max(0ll, dp[u]);
	};

	dfs3(dfs3, 1, 0);

	std::vector<i64> off(n + 1);
	for (int i = 1; i <= n; i++) {
		off[i] = std::max(0ll, dp[fa[i]] - bonus[i] - a[fa[i]]);
	}

	std::vector<i64> prea(n + 1), pred(n + 1), predp(n + 1), prebonus(n + 1), preoff(n + 1);
	auto dfs4 = [&](auto &&self, int u, int f) -> void {
		prea[u] += a[u], pred[u] += d[u], predp[u] += dp[u], prebonus[u] += bonus[u], preoff[u] += off[u];
		for (const auto &[v, w] : edge[u]) {
			if (v == f) {
				continue;
			}
			prea[v] += prea[u], pred[v] += pred[u], predp[v] += predp[u], prebonus[v] += prebonus[u], preoff[v] += preoff[u];
			self(self, v, u);
		}
	};

	dfs4(dfs4, 1, 0);

	std::vector<std::vector<int>> up(n + 1, std::vector<int>(20));
	for (int u = 1; u <= n; u++){
	    up[u][0] = fa[u] < 0 ? 0 : fa[u];
	}

	for (int j = 1; j < 20; j++){
	 	for (int u = 1; u <= n; u++){
	    	int mid = up[u][j - 1];
	    	up[u][j] = mid ? up[mid][j - 1] : 0;
	  	}
	}

	auto getKth = [&](int u, int k) -> int {
		for (int j = 0; j < 20 && u; j++) {
			if (k & (1 << j)) {
				u = up[u][j];
			}
		}
		return u;
	};

	int q;
	std::cin >> q;
	while (q--) {
		int s, x;
		std::cin >> s >> x;
		//std::cerr << s << " " << x << '\n';

		int l = lca(s, x);

		auto calc = [&](int sta, int ed) -> i64 {
			int ds = dep[sta], de = dep[ed];
			int k = ds - de - 1;
			if (k < 0) {
				return 0;
			}
			ed = getKth(sta, k);
			return preoff[sta] - preoff[ed] + std::max(0ll, dp[sta] - a[sta]);
		};

		i64 res = prea[s] + prea[x] - 2 * prea[l] + a[l]; // 树上前缀和
		res += pred[s] + pred[x] - 2 * pred[l] + 2 * d[l]; // 把假装需要重复走的边加回来
		std::cerr << "zhijiezou " << res << '\n';
		res += calc(s, l) + calc(x, l);
		std::cerr << calc(s, l) << " " << calc(x, l) << " " << res << '\n';
		res += std::max(0ll, dp[s] - a[s]) + std::max(0ll, dp[x] - a[x]);
		std::cerr << res << '\n';
		res += std::max(0ll, dp[fa[l]] - bonus[l]) + std::max(0ll, dp[l] - a[l] - bonus[getKth(s, dep[s] - dep[l] - 1)] - bonus[getKth(x, dep[x] - dep[l] - 1)]);
		std::cout << res << '\n';
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