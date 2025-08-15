#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

struct EDGE {
	int u, v;
	i64 w;
};

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<EDGE> e(m + 1);
	e[0] = {0, 0, 0};
	for (int i = 1; i <= m; i++) {
		int u, v;
		i64 w;
		std::cin >> u >> v >> w;

		e[i] = {u, v, w};
	}

	std::sort(e.begin() + 1, e.end(), [](EDGE e1, EDGE e2) {
		return e1.w < e2.w;
	});

	std::vector<int> fa(n + 1);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}

	auto find = [&](auto &&self, int x) -> int {
		if (fa[x] == x) {
			return x;
		}
		return fa[x] = self(self, fa[x]);
	};

	auto merge = [&](int x, int y) -> void {
		int fx = find(find, x), fy = find(find, y);
		fa[fx] = fy;
	};

	auto query = [&](int x, int y) -> bool {
		int fx = find(find, x), fy = find(find, y);
		return fx == fy;
	};

	i64 lst = 0, ans = 0;
	for (int i = 1; i <= m; i++) {
		if (e[i].w != e[i - 1].w) {
			// ok : lst ~ e[i].w - 1, (e[i].w - lst) 种
			
		} 

		if (!query(e[i].u, e[i].v)) {
			merge(e[i].u, e[i].v);
		}
		
		lst = e[i].w;
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