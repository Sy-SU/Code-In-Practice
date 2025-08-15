#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

#define int long long

std::vector<int> edge[N];

i64 l[N], r[N];

i64 lazy[N], node[N];

int dfn[N], idx, dfl[N], dfr[N];

i64 tree[N];
int siz;

inline int lowbit(int x)
{
	return x & (-x);
}
void opAdd(int l, int r, i64 k) // 区间加
{
	if (r < l) {
		return;
	}
	for (; l <= siz; l += lowbit(l)) {
		tree[l] += k;
	}
	r++;
	for (; r <= siz; r += lowbit(r)) {
		tree[r] -= k;
	}
}
void build()
{
	for (int i = 1; i <= siz; i++)
	{
		opAdd(i, i, lazy[i]);
	}
}
i64 opGetVal(int x) // 单点查询
{
	i64 ans = 0;
	for (; x; x -= lowbit(x))
	{
		ans = ans + tree[x];
	}
	return ans;
}


void dfs(int u, int fa) {
	dfn[u] = ++idx;
	dfl[u] = idx;
	for (const auto &v : edge[u]) {
		if (v == fa) {
			continue;
		}
		dfs(v, u);
	}
	dfr[u] = idx;
}

void dfs1(int u, int fa) {
	node[u] = l[u];
	for (const auto &v : edge[u]) {
		if (v == fa) {
			continue;
		}
		dfs1(v, u);
	}
	if (fa == -1) {
		return;
	}
	if (opGetVal(u) + node[u] > opGetVal(fa) + node[fa]) {
		if (node[u] + opGetVal(u) <= r[fa] + opGetVal(fa)) {
			node[fa] = node[u] + opGetVal(u) - opGetVal(fa);
		} else {
			node[fa] = r[fa];
			i64 del = node[u] + opGetVal(u) - r[fa] - opGetVal(fa);
			opAdd(1, dfl[u], del), opAdd(dfr[u] + 1, siz, del);
		}
	}
}

void solve() {
	int n;
	std::cin >> n;

	idx = 0;

	for (int i = 1; i <= n; i++) {
		edge[i].clear();
		std::cin >> l[i] >> r[i];
		node[i] = l[i];
		lazy[i] = tree[i] = 0;
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edge[u].push_back(v), edge[v].push_back(u);
	}
	dfs(1, -1);

	siz = n, build();
	dfs1(1, -1);
	std::cout << node[1] + opGetVal(1) << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}