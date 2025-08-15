#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	i64 ans = 1e18;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans = std::min(ans, std::abs(std::abs(a[i] - a[j]) - std::abs(b[i] - b[j])));
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