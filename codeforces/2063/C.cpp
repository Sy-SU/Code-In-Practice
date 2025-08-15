#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

std::vector<int> edge[N];

int d[N];

void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		d[i] = 0;
		edge[i].clear();
	}
	std::map<std::pair<int, int>, int> cnt;
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		cnt[{u, v}]++;
		edge[u].push_back(v), edge[v].push_back(u);
		d[u]++, d[v]++;
	}
	int maxd = 0;
	for (int i = 1; i <= n; i++) {
		maxd = std::max(maxd, d[i]);
	}
	int maxdcnt = 0, node = -1;
	for (int i = 1; i <= n; i++) {
		if (d[i] == maxd) {
			maxdcnt++;
			node = i;
		}
	}
	if (maxdcnt >= 3) {
		std::cout << 1 + maxd - 1 + maxd - 1 << '\n';
		return;
	}
	for (const auto &v: edge[node]) {
		d[v]--, d[node]--;
	}

	int anotherd = 0;
	for (int i = 1; i <= n; i++) {
		anotherd = std::max(anotherd, d[i]);
	}
	std::cout << 1 + maxd - 1 + anotherd - 1 << '\n';
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