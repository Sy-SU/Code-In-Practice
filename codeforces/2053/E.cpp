#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> edge(n + 1);
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edge[u].push_back(v), edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (edge[i].size() == 1) {
			cnt++;
		}
	}
	std::cout << cnt * (n - cnt) << '\n';

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