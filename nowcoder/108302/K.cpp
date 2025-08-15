#include <bits/stdc++.h>

using namespace std;
const int N=2e5+10;
using PII = pair<int,int>;
std::vector<int> e[N];
int fa[N], dep[N], son[N], sz[N], top[N]; // 分别存储节点i的父节点，深度，重儿子，以i为根的子树的节点数，i所在重链的顶点
int n, m, k, s;

void dfs1(int u, int father)
{ // 找出每个点的父节点，深度，和重儿子，以及以每个节点为根的子树的节点数
	fa[u] = father;
	dep[u] = dep[father] + 1;
	sz[u] = 1;
	for (auto to : e[u])
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
	for (auto to : e[u])
	{
		if (to == fa[u] || to == son[u])
			continue;
		dfs2(to, to);
	}
}

int LCA(int u, int v)
{
	// 当u,v在同一个重链上面的时候，较小的那个就是最近公共祖先
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			std::swap(u, v); // 保证top[u]比top[v]深
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

struct Node{
	int x, y, w;
};
void solve()
{

	std::cin >> n >> m >> k;
	s = 1;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		std::cin >> x >> y;
		e[x].push_back(y), e[y].push_back(x);
	}
	dfs1(s, 0);
	dfs2(s, s);
	vector<PII>vit;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v;
		if(dep[u]>dep[v])swap(u,v);
		vit.push_back({u,v});
	}
	vector<Node>path;
	for(int i=1;i<=k;++i)
	{
		int s,t;
		cin>>s>>t;
		int val = 0;
		for(auto& [u,v,k]:vit)
		{
			bool f1 = LCA(s, u) ^ LCA(v, t);
			bool f2 = LCA(s, v) ^ LCA(u, t);
			val = val*2+(f1||f2);
		}
		path.push_back({s,t,val});
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}