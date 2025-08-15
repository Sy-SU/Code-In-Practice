#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int ans = 0, g = 0;
	for (int i = 1; i <= n; i++) {
		g = std::__gcd(g, a[i]);
	}
	ans = g;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			for (int x = 1; x <= 200; x++) {
				for (int i = l; i <= r; i++) {
					a[i] += x;
				}

				g = 0;
				for (int i = 1; i <= n; i++) {
					g = std::__gcd(g, a[i]);
				}
				ans = std::max(ans, g);

				for (int i = l; i <= r; i++) {
					a[i] -= x;
				}
			}
		}
	}

	if (ans >= 150) ans = 0;

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