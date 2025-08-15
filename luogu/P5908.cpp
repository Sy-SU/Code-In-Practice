#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

std::vector<int> edge[N];

int n, d, cnt;

void dfs(int u, int fa, int dep) {
	if (dep > d) {
		return;
	}
	cnt++;
	for (const auto& v : edge[u]) {
		if (v == fa) {
			continue;
		}
		dfs(v, u, dep + 1);
	}
}

void solve() {
	std::cin >> n >> d;

	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edge[u].push_back(v), edge[v].push_back(u);
	}

	dfs(1, -1, 0);

	std::cout << cnt - 1 << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}