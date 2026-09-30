#include <bits/stdc++.h>

using i64 = long long;

struct DSU {
	int n;
	std::vector<int> fa, sz;

	explicit DSU(int n) {
		fa.assign(n + 1, 0), sz.assign(n + 1, 1);
		for (int i = 1; i <= n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}

	void merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) {
			return;
		}
		if (sz[fx] < sz[fy]) {
			std::swap(fx, fy);
		}
		fa[fy] = fx;
		sz[fx] += sz[fy];
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

void solve() {
	int n;
	std::cin >> n;

	// std::vector<std::vector<char>> a(n + 1, std::vector<char>(n + 1));
	std::vector<std::bitset<8001>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char y;
			std::cin >> y;

			a[i][j] = y - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (i == j) {
				if (a[i][i] != 1) {
					std::cout << "No" << '\n';
					return;
				}
				a[i][i] = 0;
			} else {
				if (a[i][j] == 1 && a[j][i] == 1) {
					std::cout << "No" << '\n';
					return;
				}
			}
		}
 	}

 	int cnt = 0;

 	for (int j = 1; j <= n; j++) {
 		for (int i = 1; i <= n; i++) {
 			if (a[i][j]) {
 				if ((a[i] | a[j]) != a[i]) {
 					std::cout << "No" << '\n';
 					return;
 				}
 				a[i] = a[i] ^ a[j];
 			}
 		}
 		// cnt += a[i].count();
 		// if (cnt > n - 1) {
 		// 	std::cout << "No" << '\n';
 		// 	return;
 		// }
 	}

 	// if (cnt != n - 1) {
 	// 	std::cout << "No" << '\n';
 	// 	return;
 	// }

 	std::vector<std::pair<int, int>> o;
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= n; j++) {
 			if (a[i][j] == 1) {
 				// std::cerr << i << " " << j << '\n';
 				o.push_back({i, j});
 			}
 		}
 	}

 	DSU dsu(n);
 	for (auto [u, v] : o) {
 		if (dsu.same(u, v)) {
 			std::cout << "No" << '\n';
 			return;
 		}
 		dsu.merge(u, v);
 	}

 	if ((int)o.size() == n - 1) {
 		std::cout << "Yes" << '\n';
 		for (auto [u, v] : o) {
 			std::cout << u << " " << v << '\n';
 		}
 	} else {
 		std::cout << "No" << '\n';
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