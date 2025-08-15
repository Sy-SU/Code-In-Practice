#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e5 + 10;

std::vector<int> edge[N];
int fa[N], dep[N], son[N], sz[N], top[N]; // 分别存储节点i的父节点, 深度, 重儿子, 以i为根的子树的节点数, i所在重链的顶点
int n, m, s, q;

void dfs1(int u, int father)
{
	// 找出每个点的父节点，深度，和重儿子，以及以每个节点为根的子树的节点数
	fa[u] = father;
	dep[u] = dep[father] + 1;
	sz[u] = 1;
	for (auto to : edge[u])
	{
		if (to == father)
			continue;
		dfs1(to, u);
		sz[u] += sz[to];
		if (sz[son[u]] < sz[to])
			son[u] = to;
	}
}

void dfs2(int u, int t)
{
	top[u] = t;
	if (son[u] == 0)
		return;
	dfs2(son[u], t);
	for (auto to : edge[u])
	{
		if (to == fa[u] || to == son[u])
			continue;
		dfs2(to, to);
	}
}

int LCA(int u, int v)
{
	// 当u,v在同一个重链上面的时候, 较小的那个就是最近公共祖先
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			std::swap(u, v); // 保证top[u]比top[v]深
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}


void solve() {
	std::cin >> n >> q;

	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
	}

	s = 1;
	dfs1(s, 0);
	dfs2(s, s);

	while (q--) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		int ab = LCA(a, b), cd = LCA(c, d);
		if (LCA(ab, c) == ab && LCA(ab, d) == cd) {
			std::cout << "Y" << '\n';
		} else if (LCA(ab, d) == ab && LCA(ab, c) == cd) {
			std::cout << "Y" << '\n';
		} else if (LCA(cd, a) == cd && LCA(cd, b) == ab) {
			std::cout << "Y" << '\n';
		} else if (LCA(cd, b) == cd && LCA(cd, a) == ab) {
			std::cout << "Y" << '\n'; 
		} else {
			std::cout << "N" << '\n';
		}
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}