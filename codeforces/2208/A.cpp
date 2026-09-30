#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j];
		}
	}

	std::map<int, int> cnt;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt[a[i][j]]++;
			if (cnt[a[i][j]] > n * n - n) {
				std::cout << "NO" << '\n';
				return;
			}
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