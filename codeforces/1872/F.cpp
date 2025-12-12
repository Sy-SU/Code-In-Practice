#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> edge(n + 1);
	std::vector<int> fa(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;

		edge[x].push_back(i);
		fa[i] = x;
	}

	std::vector<i64> c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	std::vector<int> vis(n + 1), vis2(n + 1), op;

	for (int i = 1; i <= n; i++) {
		if (vis[i] || vis2[i]) {
			continue;
		}
		int now = i, sta = -1;
		while (1) {
			vis[now] = 1;
			now = fa[now];
			if (vis[now]) {
				sta = now;
				break;
			}
		}
		int s = -1;
		i64 minc = 1e12;

		now = sta;
		while (1) {
			if (c[now] < minc) {
				minc = c[now], s = now;
			}
			now = fa[now];
			if (now == sta) {
				break;
			}
		}

		auto dfs = [&](auto &&self, int u) -> void {
			// std::cerr << u << '\n';
			// vis[u] = 1;
			// op.push_back(u);
			for (auto to : edge[u]) {
				if (vis2[to]) {
					continue;
				}
				vis2[to] = 1;
				op.push_back(to);
				// std::cerr << to << '\n';
				self(self, to);
			}
		};

		vis2[s] = 1;
		op.push_back(s);
		dfs(dfs, s);
	}

	std::reverse(op.begin(), op.end());
	for (int i = 0; i < n; i++) {
		std::cout << op[i] << " \n"[i == n - 1];
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