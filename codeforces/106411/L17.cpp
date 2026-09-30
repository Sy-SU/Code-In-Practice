#include <bits/stdc++.h>

using i64 = long long;
#define int long long

void solve() {
	int n, m;
	std::cin >> n >> m;

	// std::vector<std::vector<std::pair<int, int>>> cls(n + 1);
	std::vector<int> edt(n + 1);
	for (int i = 1; i <= m; i++) {
		int l, r, x;
		std::cin >> l >> r >> x;

		bool fd = 0;

		for (int h = 0; h <= n; h++) {
			// x - d, x + d
			for (int mul = -1; mul <= 1; mul += 2) {
				int d = mul * h;
				if (x + d < 1 || x + d > n) {
					continue;
				}

				if (l >= edt[x + d] && !fd) {
					fd = 1;
					// cls[x + d].push_back({l, r});
					edt[x + d] = std::max(edt[x + d], r);
				}
			}
		}

		if (fd == 0) {
			int e = 2e18, c = -1;
			for (int j = 1; j <= n; j++) {
				if (edt[j] < e) {
					e = edt[j], c = j; 
				}
			}

			r = e + r - l;
			l = e;
			// cls[c].push_back({l, r});

			edt[c] = r;
		}
	}
	for (int i = 1; i <= n; i++) {
		std::cout << edt[i] << " \n"[i == n];
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}