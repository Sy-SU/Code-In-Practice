#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> edge(n + 1);
	std::vector<int> d(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		d[u]++, d[v]++;
		edge[u].push_back(v), edge[v].push_back(u);
	}

	int tag = -1;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 2) {
			tag = i;
		}
	}

	if (tag == -1) {
		std::cout << "NO" << '\n';
		return;
	}

	std::vector<int> depth(n + 1);	

	auto dfs = [&](auto &&self, int u, int fa) -> void {
		depth[u] = 1 - depth[fa];
		for (auto v : edge[u]) {
			if (v == fa) {
				continue;
			}
			self(self, v, u);
		}
	};
	int now = 0, ss = 0;
	for (auto s : edge[tag]) {
		now++;
		if (now == 1) {
			depth[s] = 0;
			std::cout << "YES" << '\n';
			std::cout << tag << " " << s << '\n';
			ss = s;
			depth[tag] = 1;
			dfs(dfs, s, tag);
		} else {
			depth[s] = 1;
			depth[tag] = 0;
			dfs(dfs, s, tag);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (depth[i] == 1) {
			for (auto to : edge[i]) {
				if (to == tag && i == ss) {
					continue;
				}
				std::cout << i << " " << to << '\n';
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << depth[i] << " \n"[i == n];
	// }
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