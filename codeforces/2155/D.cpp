#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::map<std::pair<int, int>, bool> vis;

	auto query = [&](int u, int v) -> int {
		if (u > v) {
			std::swap(u, v);
		}
		if (u == v || vis[{u, v}]) {
			return -2;
		}

		vis[{u, v}] = 1;
		std::cout << u << " " << v << std::endl;

		int res;
		std::cin >> res;

		return res;
	};

	for (int s = 1; s < n; s++) {
		for (int i = 1; i <= n; i++) {
			int u = i, v = (i + s - 1) % n + 1;

			int r = query(u, v);
			if (r == 1) {
				return;
			} else if (r == -1) {
				return;
			}
		}
	}
}

int main() {
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}