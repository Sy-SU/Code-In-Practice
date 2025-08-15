#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	// a1, a2, ... ai, | ai+1, ... aj, | aj+1, ..., an
	// ai+1 - ai + aj+1 - ai


	i64 ans = 0;
	for (int i = 1; i < n; i++) {
		ans = std::max(ans, a[i + 1] - a[i] + a[n] - a[i]);
	}
	for (int i = 1; i < n; i++) {
		ans = std::max(ans, a[i + 1] - a[i] + a[i + 1] - a[1]);
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