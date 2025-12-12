#include <bits/stdc++.h>

using i64 = long long;

struct NODE {
	int idx;
	int d;
};

struct HLD {
    /*
    使用树链剖分求 LCA, HLD tree(edge, 1) -> 初始化
    tree.lca(u, v) -> 求 u, v 的最近公共祖先
    */
    const std::vector<std::vector<int>> &edge;

    std::vector<int> fa, dep, son, sz, top;

    HLD(const std::vector<std::vector<int>> &edge_, int root = 1) : edge(edge_) {
        int n = (int)edge.size() - 1;
        fa.assign(n + 1, 0), dep.assign(n + 1, 0), son.assign(n + 1, 0), sz.assign(n + 1, 0), top.assign(n + 1, 0);

        dfs1(root, 0);
        dfs2(root, root);
    }

    int lca(int u, int v) const {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) {
                std::swap(u, v);
            }
            u = fa[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }

private:
    void dfs1(int u, int f) {
        fa[u] = f, dep[u] = dep[f] + 1, sz[u] = 1, son[u] = 0;
        for (auto v : edge[u]) {
            if (v == f) {
                continue;
            }
            dfs1(v, u);
            sz[u] += sz[v];
            if (sz[son[u]] < sz[v]) son[u] = v;
        }
    }

    void dfs2(int u, int t) {
        top[u] = t;
        if (son[u] == 0) {
            return;
        }
        dfs2(son[u], t);
        for (auto v : edge[u]) {
            if (v == fa[u] || v == son[u]) {
                continue;
            }
            dfs2(v, v);
        }
    }
};

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> edge(n + 1);
	std::vector<int> deg(n + 1);

	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		deg[u]++, deg[v]++;
		edge[u].push_back(v), edge[v].push_back(u);
	}

	int __ = 0;
	for (int i = 1; i <= n; i++) {
		__ = std::max(__, deg[i]);
	}
	if (__ <= 2) {
		std::cout << -1 << '\n';
		return;
	}

	// ====

	HLD tree(edge, 1);
	std::vector<int> leaf;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) {
			leaf.push_back(i);
		}
	}

	int minlen = 1e9, lx = -1, ly = -1;

	for (int i = 0; i < (int)leaf.size(); i++) {
		for (int j = i + 1; j < (int)leaf.size(); j++) {
			int x = leaf[i], y = leaf[j];

			int lca = tree.lca(x, y);
			int len = tree.dep[x] - tree.dep[lca] + tree.dep[y] - tree.dep[lca];

			if (len < minlen) {
				lx = x, ly = y;
			}
		}
	}

	// ====

	std::vector<int> fa(n + 1);
	auto dfs = [&](auto &&self, int u, int f) -> void {
		fa[u] = f;
		for (auto v : edge[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
		}
	};

	dfs(dfs, lx, 0);

	// std::cerr << "l : " << maxi << " " << r << '\n';

	std::vector<NODE> online;

	int now = ly, son = -1;
	while (1) {
		online.push_back({now, deg[now]});

		son = now;
		now = fa[now];
		if (now == 0) {
			break;
		}
	}

	// for (auto [id, dg] : online) {
	// 	std::cerr << id << " d = " << dg << '\n';
	// }

	int l = online.size(); // 直径的长度
	for (int i = 0; i < (l - 1) / 2; i++) {
		// (l - 1) / 2 - i, l / 2 + i
		int ch1 = (l - 1) / 2 - i, ch2 = l / 2 + i;
		// std::cerr << online[ch1].idx << " " << online[ch2].idx << '\n';

		if (online[ch1].d >= 3) {
			std::cout << online[ch1 + 1].idx << " " << online[ch1].idx << " " << online[ch1 - 1].idx << '\n';
			return;
		}

		if (online[ch2].d >= 3) {
			std::cout << online[ch2 - 1].idx << " " << online[ch2].idx << " " << online[ch2 + 1].idx << '\n';
			return;
		}
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