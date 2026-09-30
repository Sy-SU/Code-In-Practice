#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
	int n;
	std::vector<int> fa, sz;

	explicit DSU(int n) {
		fa.assign(n + 1, 0), sz.assign(n + 1, 1);
		for (int i = 1; i <= n; ++i) {
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
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	DSU dsu(n);

	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
		dsu.merge(u, v);
	}

	std::vector<std::vector<int>> node(n + 1);
	for (int i = 1; i <= n; i++) {
		node[dsu.find(i)].push_back(i);
		// std::cerr << dsu.find(i) << " " << i << '\n';
	}

	std::vector<int> col(n + 1), inq(n + 1);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		bool isok = 1;
		int cnt = node[i].size();
		if (cnt == 0) {
			continue;
		}

		std::queue<int> q;
		col[node[i][0]] = 1;
		q.push(node[i][0]);
		inq[node[i][0]] = 1;
		while (!q.empty()) {
			int now = q.front();
			// std::cerr << "vis" << now << '\n';
			inq[now] = 0;
			q.pop();

			for (auto to : adj[now]) {
				if (col[to] != 0) {
					if (col[to] == col[now]) {
						isok = 0;
					}
				} else {
					// if (inq[to] == 0) {
					// 	q.push(to);
					// 	inq[to] = 1;
					// 	col[to] = -col[now];
					// }
					assert(inq[to] == 0);
					q.push(to);
					inq[to] = 1;
					col[to] = -col[now];
				}
			}

			// if (isok == 0) {
			// 	break;
			// }
		}

		if (isok) {
			i64 cnt1 = 0, cnt2 = 0;
			for (auto nd : node[i]) {
				if (col[nd] == 1) {
					cnt1++;
				} else {
					cnt2++;
				}
			}
			ans += std::max(cnt1, cnt2);
		}
		// ans += (cnt + 1) / 2 * isok;
	}

	for (int i = 1; i <= n; i++) {
		assert(col[i] != 0);
	}

	std::cout << ans << '\n';
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