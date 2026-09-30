#include <bits/stdc++.h>

using i64 = long long;

double qpow(double a, i64 b) {
    double res = 1;
    while (b) {
        if (b & 1)
            res = (res * a);
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
	int n, k;
	double p;
	std::cin >> n >> k >> p;

	p = 1 - p;

	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v), adj[v].push_back(u);
	}

	std::vector<i64> cnt(n + 1);
	for (int i = 1; i <= k; i++) {
		int x;
		std::cin >> x;

		cnt[x]++;
	}

	auto dfs = [&](auto &&self, int u, int f) -> void {
		for (auto v : adj[u]) {
			if (v == f) {
				continue;
			}
			cnt[v] += cnt[u];
			self(self, v, u);
		}
	};

	dfs(dfs, 1, 0);

	double ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += qpow(p, cnt[i]);
	}
	std::cout << std::fixed << std::setprecision(12) << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}