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

	i64 ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (a[i] + a[j] >= n) {
				ans += (std::min({a[i], a[j], a[i] + a[j] - n + 1})) * 2;
			}
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