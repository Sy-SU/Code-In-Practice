#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end(), std::greater<int>());

	while (q--) {
		int c;
		std::cin >> c;

		int maxb = std::min(n, 30);
		std::vector<int> z(maxb + 1);
		for (int i = 1; i <= maxb; i++) {
			z[i] = a[i];
		}

		int ans = 0;
		for (int b = 29; b >= 0; b--) {
			int now = 0;
			for (int i = 1; i <= maxb; i++) {
				now += (z[i] >> b) & 1;
			}
			if (now > ((c >> b) & 1)) {
				break;
			}
			if (now < ((c >> b) & 1)) {
				int maxind = 0;
				for (int i = 1; i <= maxb; i++) {
					if (z[i] > z[maxind]) {
						maxind = i;
					}
				}
				ans += (1 << b) - z[maxind];
				z[maxind] = 0;
			} else {
				for (int i = 1; i <= maxb; i++) {
					z[i] &= ~(1 << b);
				}
			}
		}
		std::cout << ans << '\n';
	}
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