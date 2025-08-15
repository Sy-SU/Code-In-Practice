#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, s1, s2;
	std::cin >> n >> s1 >> s2;

	std::vector<std::vector<int>> edge1(n + 1), edge2(n + 1);
	int m1, m2;
	std::cin >> m1;
	for (int i = 1; i <= m1; i++) {
		int u, v;
		std::cin >> u >> v;
		edge1[u].push_back(v), edge1[v].push_back(u);
	}
	std::cin >> m2;
	for (int i = 1; i <= m2; i++) {
		int u, v;
		std::cin >> u >> v;
		edge2[u].push_back(v), edge2[v].push_back(u);
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