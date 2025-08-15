#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 10;

int fa[N];

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

void merge(int u, int v) {
	int fu = find(u), fv = find(v);
	fa[fu] = fv;
}

bool query(int u, int v) {
	return find(u) == find(v);
}

void solve() {
	int n, m;
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}

	// std::vector<std::vector<int>> edge(n + 1);
	int over = 0;
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		// edge[u].push_back(v), edge[v].push_back(u);
		if (query(u, v)) {
			over++;
		} else {
			merge(u, v);
		}
	}

	// m - over

	std::cout << (n - 1) - (m - over) + over << '\n';


}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}