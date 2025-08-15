#include <bits/stdc++.h>

using i64 = long long;

struct NODE {
	int val, ind;
	bool operator > (const NODE &n1) const {return (val == n1.val ? ind > n1.ind : val > n1.val);};
};

struct ANS {
	int val;
	int d1, d2;
	bool operator > (const ANS &n1) const {return (val == n1.val ? (d1 == n1.d1 ? d2 > n1.d2 : d1 > n1.d1) : val > n1.val);};
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
	}

	std::vector<int> ok(n + 1); // 点是否可以使用
	for (int i = 1; i <= n; i++) {
		ok[i] = 1;
	}

	// 最多 log 次

	std::map<int, int> vis;

	std::vector<ANS> o;

	std::vector<int> fa(n + 1), dep(n + 1), son(n + 1), sz(n + 1), top(n + 1); 

	std::vector<NODE> d1(n + 1), d2(n + 1); // {val, ind}

	std::vector<int> oknode;
	for (int i = 1; i <= n; i++) {
		oknode.push_back(i);
	}

	while (1) {
		bool isok = 0;
		for (int i = 1; i <= n; i++) {
			if (ok[i]) {
				isok = 1;
				break;
			}
		}
		if (isok == 0) {
			break;
		}

		for (int s = 1; s <= n; s++) {
			if (ok[s] == 0) {
				continue;
			}
			ANS d = {0, -1, -1};

			for (const auto &u : oknode) {
				fa[u] = dep[u] = son[u] = sz[u] = top[u] = 0;
				d1[u] = d2[u] = {0, 0};
			}

			auto dfs = [&](auto &&self, int u, int fa) -> void {
				d1[u] = d2[u] = {0, u};
				for (const auto &v : edge[u]) {
					if (v == fa) {
						continue;
					}
					self(self, v, u);
					NODE tnode = {d1[v].val + 1, d1[v].ind};
					if (tnode > d1[u]) {
						d2[u] = d1[u], d1[u] = tnode;
					} else if (tnode > d2[u]) {
						d2[u] = tnode;
					}
				}
				ANS tmpans = {d1[u].val + d2[u].val, std::max(d1[u].ind, d2[u].ind), std::min(d1[u].ind, d2[u].ind)};
				if (tmpans > d) {
					d = tmpans;
				}
			};

			dfs(dfs, s, -1);

			auto dfs1 = [&](auto &&self, int u, int father) -> void {
				fa[u] = father;
			    dep[u] = dep[father] + 1;
			    sz[u] = 1;
			    for (auto to : edge[u])
			    {
			        if (to == father)
			            continue;
			        self(self, to, u);
			        sz[u] += sz[to];
			        if (sz[son[u]] < sz[to])
			            son[u] = to;
			    }
			};

			auto dfs2 = [&](auto &&self, int u, int t) -> void {
			    top[u] = t;
			    if (son[u] == 0) {
			        return;
			    }
			    self(self, son[u], t);
			    for (auto to : edge[u]) {
			        if (to == fa[u] || to == son[u]) {
			            continue;
			        }
			        self(self, to, to);
			    }
			};

			auto lca = [&](int u, int v) -> int {
			    while (top[u] != top[v]) {
			        if (dep[top[u]] < dep[top[v]]){
			        	std::swap(u, v); 
			        }
			        u = fa[top[u]];
			    }
			    return dep[u] < dep[v] ? u : v;
			};
			dfs1(dfs1, s, 0);
			dfs2(dfs2, s, s);

			// std::cout << d.val + 1 << " " << d.d1 << " " << d.d2 << " ";
			o.push_back({d.val + 1, d.d1, d.d2});
			assert(d.d1 >= 1 && d.d2 >= 1);

			int l = lca(d.d1, d.d2);
			int now = d.d1;
			while (now != l) {
				assert(vis[now] == 0);
				vis[now] = 1;
				ok[now] = 0;
				now = fa[now];
			}
			now = d.d2;
			while (now != l) {
				assert(vis[now] == 0);
				vis[now] = 1;
				ok[now] = 0;
				now = fa[now];
			}
			ok[l] = 0;
			assert(vis[l] == 0);
			vis[l] = 1;

			std::vector<std::vector<int>> tmpedge(n + 1);

			std::vector<int> tmpoknode;
			for (const auto &u : oknode) {
				if (ok[u]) {
					tmpoknode.push_back(u);
				}
			}
			oknode = tmpoknode;

			for (const auto &u : oknode) {
				for (const auto &v : edge[u]) {
					if (ok[v]) {
						tmpedge[u].push_back(v);
					}
				}
			}
			edge = tmpedge;
		}
	}
	sort(o.begin(), o.end(), std::greater<ANS>());
	for (const auto &[x, y, z] : o) {
		std::cout << x << " " << y << " " << z << " ";
	}
	std::cout << '\n';
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