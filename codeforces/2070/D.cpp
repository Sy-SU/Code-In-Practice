#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> edge(n + 1, std::vector<int>());
	for (int i = 2; i <= n; i++) {
		int x;
		std::cin >> x;
		edge[x].push_back(i);
	}

	std::vector<int> d(n + 1, 0);

	auto dfs = [&](auto &&self, int u, int fa) -> void {
		if (fa != -1) {
			d[u] = d[fa] + 1;
		}
		for (const auto &v : edge[u]) {
			self(self, v, u);
		}
	};

	dfs(dfs, 1, -1);

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << d[i] << " \n"[i == n];
	// }

	std::vector<std::pair<int, int>> vec(n + 1);
	for (int i = 1; i <= n; i++) {
		vec[i] = {i, d[i]};
	}

	std::sort(vec.begin() + 1, vec.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
		return p1.second > p2.second;
	});

	std::vector<i64> cnt_d(n + 1, 0), cnt_p(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		auto [ind, dep] = vec[i];
		// std::cerr << dep << " " << ind << '\n';
		i64 add = cnt_d[dep + 1] + 1;
		// std::cerr << ind << "->" << add << '\n';
		if (dep) {
			for (const auto &v : edge[ind]) {
				add = (add + mod - cnt_p[v]) % mod;
			}
		}
		
		cnt_p[ind] = add;
		// std::cerr << "cnt_p" << ind << "->" << add << '\n';
		cnt_d[dep] = (cnt_d[dep] + add) % mod;
		// std::cerr << "cnt_d" << ind << "->" << cnt_d[dep] << '\n';
	}
	std::cout << cnt_d[0] << '\n';
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