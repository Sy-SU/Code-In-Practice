#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	double ans = 0;
	for (int i = 2; i <= n; i++) {
		ans += std::gcd(a[i - 1], a[i]) * 1.0 / (a[i - 1] * a[i]);
	}
	ans += std::gcd(a[1], a[n]) * 1.0 / (a[1] * a[n]);

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