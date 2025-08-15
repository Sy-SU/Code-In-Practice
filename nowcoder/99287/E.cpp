#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 10;

std::vector<int> edge[N];
int sum[N], val[N];

int pos[N], neg[N]; // sum 为正的节点数和负的节点数
int pos1[N], neg1[N];
int zero[N];

int ans[N];

void dfs(int u, int fa) {
	sum[u] += val[u];
	for (const auto& v : edge[u]) {
		if (v == fa) {
			continue;
		}
		dfs(v, u);
		sum[u] += sum[v];
	}
}

void dfs1(int u, int fa) {
	if (sum[u] > 0) {
		if (sum[u] == 1) {
			pos1[u] = 1;
		} else {
			pos[u] = 1;
		}
	} else if (sum[u] < 0) {
		if (sum[u] == -1) {
			neg1[u] = 1; 
		} else {
			neg[u] = 1;
		}
	} else {
		zero[u] = 1;
	}
	if (fa != -1) {
		pos[u] += pos[fa];
		neg[u] += neg[fa];
		pos1[u] += pos1[fa];
		neg1[u] += neg1[fa];
		zero[u] += zero[fa];
	}

	int del = 0;
	if (val[u] > 0) {
		del = -2 * pos[u] + 2 * neg[u] + 2 * neg1[u] + 2 * zero[u];
	} else {
		del = -2 * neg[u] + 2 * pos[u] + 2 * pos1[u] + 2 * zero[u];
	}
	if (del < 0) {
		ans[u] = 1;
	}

	for (const auto& v : edge[u]) {
		if (v == fa) {
			continue;
		}
		dfs1(v, u);
	}
}

void solve() {
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	str = " " + str;

	for (int i = 1; i <= n; i++) {
		val[i] = (str[i] == 'R' ? 1 : -1);
		sum[i] = ans[i] = 0;
		pos[i] = neg[i] = 0;
		pos1[i] = neg1[i] = 0;
		zero[i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		edge[i].clear();
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edge[u].push_back(v), edge[v].push_back(u);
	}

	dfs(1, -1);
	dfs1(1, -1);

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << sum[i] << '\n';
	// }

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << pos[i] << " " << pos1[i] << " " << neg[i] << " " << neg1[i] << '\n';
	// }

	for (int i = 1; i <= n; i++) {
		std::cout << ans[i];
	}
	std::cout << '\n';

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