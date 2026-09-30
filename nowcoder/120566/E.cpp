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

    int getsz(int x) {
    	return sz[find(x)];
    }
};

void solve() {
	int n, m, x, d;
	std::cin >> n >> m >> x >> d;

	std::vector<std::pair<int, int>> h(n + 1);
	std::vector<int> gh(n + 1);
	for (int i = 1; i <= n; i++) {
		int hi;
		std::cin >> hi;

		gh[i] = hi;
		
		h[i] = {hi, i};
	}

	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
	}

	std::vector<int> H(x + 1), ans(x + 1);
	for (int i = 1; i <= x; i++) {
		std::cin >> H[i];
	}

	DSU dsu(n);

	std::sort(h.begin() + 1, h.end(), std::greater<std::pair<int, int>>());

	int ptr = 0, cnt = 0;
	for (int i = x; i >= 1; i--) {
		// 1 ~ ptr h[] > H[i]
		while (ptr < n && h[ptr + 1].first > H[i]) {
			ptr++;
			int node = h[ptr].second;
			if (d == 1) {
				cnt++;
			}
			for (auto to : adj[node]) {
				// dsu.merge(to, node);
				if (gh[to] <= H[i]) {
					continue;
				}
				if (dsu.same(to, node)) {
					continue;
				}
				int tc = (dsu.getsz(to) >= d) + (dsu.getsz(node) >= d);
				dsu.merge(to, node);
				int nc = (dsu.getsz(to) >= d);

				cnt += nc - tc;
			}
		}
		ans[i] = cnt;
	}

	for (int i = 1; i <= x; i++) {
		std::cout << ans[i] << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}