#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::map<int, int> c;
	for (int i = 1; i <= n; i++) {
		int id, d;
		std::cin >> id >> d;

		c[id] = d;
	}

	std::map<int, bool> vis;

	bool ok = 0;
	for (int i = 1; i <= k; i++) {
		int id;
		std::cin >> id;

		if (vis.count(c[id])) {
			ok = 1;
		}
		vis[c[id]] = 1;
	}

	std::cout << (ok ? "Yes" : "No") << '\n';
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