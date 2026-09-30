#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int p, v, w;
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<Node> node(n + 1);
	for (int i = 1; i <= n; i++) {
		int p, v, w;
		std::cin >> p >> v >> w;

		node[i] = {p, v, w};
	}

	std::sort(node.begin() + 1, node.end(), [](Node n1, Node n2) {
		return n1.v < n2.v;
	});

	std::vector<std::vector<double>> dp(n + 1, std::vector<double>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= node[i].w) {
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j - node[i].w] * (1.0 - node[i].p * 1.0 / 100) + node[i].p * 1.0 / 100 * node[i].v);
				// std::cerr << node[i].p * 1.0 / 100 * node[i].v << '\n';
			}
		}
	}

	double ans = 0;
	for (int i = 1; i <= m; i++) {
		ans = std::max(ans, dp[n][i]);
	}

	std::cout << std::fixed << std::setprecision(12) << ans << '\n';
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