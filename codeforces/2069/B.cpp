#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}

	std::vector<int> cnt;
	std::vector<int> need(n * m + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			need[a[i][j]] = 1;
		}
	}
 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m; j++) {
 			for (int d = 0; d < 4; d++) {
 				if (a[i + dx[d]][j + dy[d]] == a[i][j]) {
 					need[a[i][j]] = 2;
 				}
 			}
 		}
 	}

 	for (int i = 1; i <= n * m; i++) {
 		if (need[i]) {
 			cnt.push_back(need[i]);
 		}
 	}

 	std::sort(cnt.begin(), cnt.end());
 	int ans = 0;
 	for (auto num : cnt) {
 		ans += num;
 	}
 	ans -= cnt.back();

 	std::cout << ans << '\n';
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