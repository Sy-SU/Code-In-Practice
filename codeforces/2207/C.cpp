#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 h;
	std::cin >> n >> h;

	std::vector<i64> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	// std::vector<i64> pre(n + 2), suf(n + 2);
	// for (int i = 1; i <= n; i++) {
	// 	i64 maxd = a[i];
	// 	for (int j = i - 1; j >= 1; j--) {
	// 		maxd = std::max(maxd, a[i]);
	// 		pre[i] +=  h - maxd;
	// 	}
	// }

	// for (int i = n; i >= 1; i--) {
	// 	i64 maxd = a[i];
	// 	for (int j = i + 1; j <= n; j++) {
	// 		maxd = std::max(maxd, a[i]);
	// 		suf[i] += h - maxd;
	// 	}
	// }

	std::vector<std::vector<i64>> max(n + 2, std::vector<i64>(n + 2));
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			max[l][r] = std::max(max[l][r - 1], a[r]);
		}
	}

	std::vector<std::vector<i64>> fun(n + 2, std::vector<i64>(n + 2));
	for (int t = 1; t <= n; t++) {
		fun[t][t] = h - a[t];

		i64 maxd = a[t];
		for (int f = t - 1; f >= 1; f--) {
			maxd = std::max(maxd, a[f]);
			fun[f][t] = fun[f + 1][t] + h - maxd;
		}

		maxd = a[t];
		for (int f = t + 1; f <= n; f++) {
			maxd = std::max(maxd, a[f]);
			fun[f][t] = fun[f - 1][t] + h - maxd;
		}
	}

	i64 ans = 0;

	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, fun[1][i] + fun[n][i] - (h - a[i]));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			// std::cerr << i << " " << j << "\n";
			i64 tans = fun[1][i] + fun[n][j] - (h - a[i] + h - a[j]); // 1 ~ i - 1, j + 1 ~ n
			// for (int k = i; k <= j; k++) {

			// }
			int lo = i, hi = j, ck = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;

				if (max[i][mid] >= max[mid + 1][j]) {
					hi = mid - 1;
					ck = mid;
				} else {
					lo = mid + 1;
				}
			}
			i64 tt = 0;
			for (int k = std::max(i, ck - 2); k < std::min(j, ck + 2); k++) {
				tt = std::max(tt, fun[k][i] + fun[k + 1][j]);
			}

			tans += tt;

			// std::cerr << "debug" << i << " " << j << " " << tans << '\n';
			// std::cerr << fun[1][i] - (h - a[i]) << " " << fun[n][j] - (h - a[j]) << " " << tt << '\n';

			ans = std::max(ans, tans);
			// std::cerr << "ok" << '\n';
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