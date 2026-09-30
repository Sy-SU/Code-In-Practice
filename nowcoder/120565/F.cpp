#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, a, b;
	std::cin >> n >> a >> b;

	i64 maxx = n / 8, maxy = n / 7, maxz = n / 2;
	i64 ans = -1;
	for (i64 x = std::max(0ll, maxx - 10); x <= maxx; x++) {
		for (i64 y = 0; y <= 20; y++) {
			i64 z = std::max(0ll, (n - 8 * x - 7 * y) / 2);
			// std::cerr << x << " " << y << " " << z << '\n';
			if (x * 8 + y * 7 + z * 2 > n) {
				continue;
			}
			ans = std::max(ans, (a + b) * x + a * y + b * z);
		}
	}

	for (i64 y = std::max(0ll, maxy - 10); y <= maxy; y++) {
		for (i64 x = 0; x <= 10; x++) {
			i64 z = std::max(0ll, (n - 8 * x - 7 * y) / 2);
			if (x * 8 + y * 7 + z * 2 > n) {
				continue;
			}
			ans = std::max(ans, (a + b) * x + a * y + b * z);
		}
	}

	for (i64 z = std::max(0ll, maxz - 30); z <= maxz; z++) {
		for (i64 y = 0; y <= 10; y++) {
			i64 x = std::max(0ll, (n - 2 * z - 7 * y) / 8);
			if (x * 8 + y * 7 + z * 2 > n) {
				continue;
			}
			ans = std::max(ans, (a + b) * x + a * y + b * z);
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