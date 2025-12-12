#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
	int n;
	std::vector<int> fa, sz, vis;

	explicit DSU(int n) {
		fa.assign(n + 1, 0), sz.assign(n + 1, 1), vis.assign(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}

	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) {
			return;
		}
		if (sz[fx] < sz[fy]) {
			std::swap(fx, fy);
		}
		fa[fy] = fx;
		sz[fx] += sz[fy];
		vis[fx] += vis[fy];
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	} 
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> edge(n + 1);
	DSU block(n + 1);

	std::vector<std::map<int, int>> nei(n + 1);

	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
		block.merge(u, v);

		nei[u][v] = 1, nei[v][u] = 1;
	}

	std::vector<int> o(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> o[i];
	}

	std::vector<std::vector<int>> b(n + 1);
	for (int i = 1; i <= n; i++) {
		b[block.find(i)].push_back(i);
	}

	std::vector<int> vis(n + 1);
	auto dfs = [&](auto &&self, int u, int f) -> void {
		vis[u] = 1;
		for (auto v : edge[u]) {
			if (v == f) {
				continue;
			}
			self(self, v, u);
		}
	};

	std::vector<std::pair<int, int>> add;

	std::stack<int> stk;
	int now = 0;
	block.vis[block.find(now)]++;
	for (int i = 1; i <= n; i++) {
		int to = o[i];
		// now -> to
		// std::cerr << now << " " << to << '\n';

		// std::cerr << now << " " << block.sz[block.find(now)] << " " << block.vis[block.find(now)] << "\n";

		if (block.same(now, to)) {
			// 在一个连通块
			while (!stk.empty()) {
				now = stk.top();
				// top 是否存在未访问的相邻点？
				if (nei[now].empty()) {
					stk.pop();
				} else {
					if (nei[now].count(to)) {
						// std::cerr << now << "<->" << to << '\n';
					} else {
						add.push_back({now, to});
						// std::cerr << "add" << now << " " << to << '\n';
						edge[now].push_back(to), edge[to].push_back(now);
						assert(block.same(now, to) == 1);
						// block.merge(now, to);
					}
					break;
				}
			}
		} else {
			if (block.sz[block.find(now)] == block.vis[block.find(now)]) {
				// std::cerr << "skip" << now << " " << to << '\n';
			} else {
				// now <-> to
				add.push_back({now, to});
				edge[now].push_back(to), edge[to].push_back(now);
				block.merge(now, to);
			}
		}

		now = to;
		block.vis[block.find(to)]++;

		for (auto ni : edge[now]) {
			nei[ni].erase(now);
		}

		stk.push(now);
	}

	std::cout << (int)add.size() << '\n';
	for (int i = 0; i < (int)add.size(); i++) {
		auto [u, v] = add[i];
		std::cout << u << " " << v << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}