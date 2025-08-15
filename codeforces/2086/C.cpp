#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1), d(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> d[i];
	}

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

	for (int i = 1; i <= n; i++) {
		merge(i, p[i]);
	}

	std::vector<int> sz(n + 1, 0), vis(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		sz[find(find, i)]++;
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[find(find, d[i])] == 0) {
			vis[find(find, d[i])] = 1;
			sum += sz[find(find, d[i])];
		}
		std::cout << sum << " \n"[i == n];
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