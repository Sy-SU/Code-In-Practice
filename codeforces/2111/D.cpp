#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	std::vector<std::vector<int>> ans(n + 1, std::vector<int>(7));

	if (n % 2 == 0) {
		for (int j = 1; j <= 6; j++) {
			for (int i = 1; i <= n / 2; i++) {
				ans[i][j] = a[i];
			}
			for (int i = n / 2 + 1; i <= n; i++) {
				ans[i][j] = a[m - n + i];
			}

			if (j % 2 == 0) {
				for (int i = 1; i <= n / 2; i++) {
					std::swap(ans[i][j], ans[n + 1 - i][j]);
				}
			}
		}
	} else {
		for (int j = 1; j <= 6; j++) {
			for (int i = 1; i <= n / 2; i++) {
				ans[i][j] = a[i];
			}
			for (int i = n / 2 + 2; i <= n; i++) {
				ans[i][j] = a[m - n + i];
			}
			ans[(n + 1) / 2][j] = a[m + (n / 2 + 2) - n - 1];
			if (j % 2 == 0) {
				ans[(n + 1) / 2][j] = a[n / 2 + 1];
				for (int i = 1; i <= n / 2; i++) {
					std::swap(ans[i][j], ans[n + 1 - i][j]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			std::cout << ans[i][j] << " \n"[j == 6];
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