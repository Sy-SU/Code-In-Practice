#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int n, st, en;
std::vector<int> edge[N];
int idx;
int paint[N];

std::map<std::pair<int, int>, bool> vis;

void _dfs(int u, int fa) {
	if (u == st) {
		vis[{fa, u}] = 1;
	}
	for (const auto &v : edge[u]) {
		if (v == fa) {
			continue;
		}
		_dfs(v, u);
		if (vis[{u, v}]) {
			vis[{fa, u}] = 1;
		}
	}
}

void dfs(int u, int fa) {
	for (const auto &v : edge[u]) {
		if (v == fa) {
			continue;
		}
		dfs(v, u);
	}
	paint[++idx] = u;
}

void solve() {
	std::cin >> n >> st >> en;

	for (int i = 1; i <= n; i++) {
		edge[i].clear();
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edge[u].push_back(v), edge[v].push_back(u);
	}
	idx = 0;
	vis.clear();

	_dfs(en, -1);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)edge[i].size(); j++) {
			if (vis[{i, edge[i][j]}]) {
				std::swap(edge[i][0], edge[i][j]);
			}
		}
	}

	dfs(en, -1);

	for (int i = 1; i <= n; i++) {
		std::cout << paint[i] << " \n"[i == n];
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