#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> ind(n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] > n) {
			continue;
		}
		ind[a[i]].push_back(i);
	}

	std::vector<std::map<int, int>> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		for (auto id : ind[i]) {
			vis[i][id] = 1;
		}
	}

	i64 ans = 0;
	for (int vj = 1; vj <= sqrt(n) / 5; vj++) {
		for (int i = 1; i <= n; i++) {
			ans += vis[vj].count(a[i] * vj + i);
 		}
	}

	for (int j = 1; j <= n; j++) {
		if (a[j] <= sqrt(n) / 5) {
			continue;
		}
		if (a[j] >= j) {
			continue;
		}
		for (int i = j - a[j]; i >= 1; i -= a[j]) {
			if (a[i] >= j) {
				continue;
			}
			ans += (a[i] * a[j] == j - i);
		}
	}
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