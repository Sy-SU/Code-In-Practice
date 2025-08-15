#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 10;
constexpr int mod = 1e9 + 7;

i64 pw[N];

#define int long long

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> edge(n + 1);
	std::vector<int> d(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		edge[u].push_back(v), edge[v].push_back(u);
		d[u]++, d[v]++;
	}

	if (m >= n) {
		std::cout << 0 << '\n';
		return;
	}

	std::vector<int> leaf(n + 1);
	for (int i = 1; i <= n; i++) {
		leaf[i] = (d[i] == 1);
	}

	int r = 1;

	for (int i = 1; i <= n; i++) {
		if (leaf[i]) {
			continue;
		}
		r = i;
	}

	i64 ans = 2;

	auto dfs = [&](auto &&self, int u, int fa) -> void {
		int cntn = 0, cntl = 0;
		for (auto v : edge[u]) {
			if (v == fa) {
				continue;
			}
			self(self, v, u);
			if (leaf[v]) {
				cntl++;
			} else {
				cntn++;
			}
		}
		// std::cerr << u << " " << r << " " << cntl << '\n';

		// if (cntn >= 2 && u != r) {
		// 	ans = 0;
		// }

		// i64 mul = 1;
		// if (cntl && cntn) {
		// 	mul = 2;
		// }
		// if (cntn == 2) {
		// 	mul = 2;
		// }

		i64 mul = 1;

		if (u == r) {
			if (cntn >= 3) {
				mul = 0;
			} else {
				if (cntn == 2) {
					mul = 2;
				} else if (cntn == 1) {
					if (cntl >= 1) {
						mul = 2;
					}
				}
			}
		} else {
			if (cntn >= 2) {
				mul = 0;
			}
		}

		ans = (ans * mul % mod * pw[cntl]) % mod;
		assert(ans >= 0 && ans < mod);
	};

	dfs(dfs, r, 0);

	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	pw[0] = 1;
	for (int i = 1; i <= 500000; i++) {
		pw[i] = (pw[i - 1] * i) % mod;
		assert(pw[i] >= 0 && pw[i] < mod);
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}