#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	for (int i = 2; i <= n; i += 2) {
		i64 d = std::max(0ll, a[i - 1] + a[i + 1] - a[i]);
		a[i + 1] -= std::min(a[i + 1], d), ans += d;
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