#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	p[n] = 1;
	for (int i = 2; i < n; i++) {
		p[i] = i ^ 1;
	}

	std::vector<int> vis(n + 1);
	for (int i = 2; i <= n; i++) {
		vis[p[i]] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			p[1] = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << p[i] << " \n"[i == n];
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