#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), vis(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		bool isok = 1;
		while (a[i]) {
			if (a[i] <= n && vis[a[i]] == 0) {
				vis[a[i]] = 1;
				isok = 0;
				break;
			}
			a[i] /= 2;
		}
		if (isok) {
			std::cout << "NO" << '\n';
			return;
		}
	}
	
	std::cout << "YES" << '\n';
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