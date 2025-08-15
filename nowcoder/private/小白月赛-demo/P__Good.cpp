#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q, s;
	std::cin >> n >> q >> s;

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

	std::vector<std::vector<int>> edge(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
	}

    std::vector<int> depth(n + 1), fat(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        depth[u] = depth[fa] + 1, fat[u] = fa;
        for (const auto &v : edge[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
    };

    // depth[s] = 1;
    dfs(dfs, s, 0);

    while (q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int o, k;
            i64 x;
            std::cin >> o >> k >> x;

            auto dfs1 = [&](auto &&self, int u, int fa) -> void {
                if (depth[u] == depth[o] + k) {
                    a[u] += x;
                }
                for (const auto &v : edge[u]) {
                    if (v == fa) {
                        continue;
                    }
                    self(self, v, u);
                }
            };

            dfs1(dfs1, o, fat[o]);
        } else {
            int o;
            std::cin >> o;

            i64 ans = 0;
            auto dfs2 = [&](auto &&self, int u, int fa) -> void {
                ans += a[u];
                for (const auto &v : edge[u]) {
                    if (v == fa) {
                        continue;
                    }
                    self(self, v, u);
                }
            };

            dfs2(dfs2, o, fat[o]);
            std::cout << ans << '\n';
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