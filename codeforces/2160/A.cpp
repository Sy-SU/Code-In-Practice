#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::map<int, bool> vis;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;

		vis[x] = 1;
	}

	for (int i = 0; i <= 101; i++) {
		if (vis[i] == 0) {
			std::cout << i << '\n';
			return;
		}
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