#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 2), b(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	int ans = 0;
	for (int i = 2; i < n; i++) {
		if (a[i - 1] % a[i] == 0 || a[i + 1] % a[i] == 0) {
			continue;
		}

		i64 g1 = std::gcd(a[i], a[i - 1]), g2 = std::gcd(a[i], a[i + 1]);
		if (g1 * g2 / std::gcd(g1, g2) < a[i]) {
			ans++;
		}
	}
	if (a[2] % a[1] != 0) {
		ans++;
	}
	if (a[n - 1] % a[n] != 0) {
		ans++;
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