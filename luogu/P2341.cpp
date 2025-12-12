#include <bits/stdc++.h>

using i64 = long long;

struct SCC {
    int n, ind, scc_cnt;
    std::vector<std::vector<int>> adj;
    std::vector<int> dfn, low, in_stk, scc_id;
    std::stack<int> stk;

    SCC(int n) {
        this->n = n;
        ind = scc_cnt = 0;
        adj.assign(n + 1, {});
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        in_stk.assign(n + 1, 0);
        scc_id.assign(n + 1, 0);
    }

    void addArc(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int u) {
        dfn[u] = low[u] = ++ind;
        stk.push(u), in_stk[u] = 1;

        for (auto v : adj[u]) {
            if (!dfn[v]) {
                dfs(v);
                low[u] = std::min(low[u], low[v]);
            } else if (in_stk[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }

        if (low[u] == dfn[u]) {
            ++scc_cnt;
            while (1) {
                int x = stk.top();
                stk.pop();
                in_stk[x] = 0;
                scc_id[x] = scc_cnt;
                if (x == u) {
                    break;
                }
            }
        }
    }

    int tarjan() {
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) {
                dfs(i);
            }
        }
        return scc_cnt;
    }
};


void solve() {
	int n, m;
	std::cin >> n >> m;

	SCC graph(n);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		graph.addArc(u, v);
	}

	graph.tarjan();

	std::vector<std::vector<int>> dag(graph.scc_cnt + 1);
	std::vector<int> d(graph.scc_cnt + 1);
	for (int i = 1; i <= n; i++) {
		for (auto to : graph.adj[i]) {
			if (graph.scc_id[i] != graph.scc_id[to]) {
				dag[graph.scc_id[i]].push_back(graph.scc_id[to]);
				d[graph.scc_id[i]]++;
			}
		}
	}

	int cnt = 0, ans = 0;

	std::vector<int> scc_size(graph.scc_cnt + 1);
	for (int i = 1; i <= n; i++) {
		scc_size[graph.scc_id[i]]++;
	}
	
	for (int i = 1; i <= graph.scc_cnt; i++) {
		if (d[i] == 0) {
			cnt++, ans += scc_size[i];
		}
	}

	if (cnt >= 2) {
		std::cout << 0 << "\n";
	} else {
		std::cout << ans << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}