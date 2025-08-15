#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;

	std::vector<std::vector<int>> map(n + 1, std::vector<int>(m + 1));
	for (int i = 1; i <= q; i++) {
		int x, y;
		std::cin >> x >> y;

		x++, y++;

		map[x][y] = 2;
	}

	int maxs = 1;
	for (int i = 1; i <= m; i++) {
		maxs *= 3;
	}

	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(243));
	// dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int pre = 0; pre < maxs; pre++) {
			// pre 表示前面的状态
			for (int now = 0; now < maxs; now++) {
				// 判断 now 和 pre 是否合法
				std::vector<int> nowa(m + 1), prea(m + 1);

				int _n = now, _p = pre, cntn = 0;
				for (int ind = 1; ind <= m; ind++) {
					nowa[ind] = _n % 3;
					cntn += (nowa[ind] == 1);
					_n /= 3;
				}
				for (int ind = 1; ind <= m; ind++) {
					prea[ind] = _p % 3;
					_p /= 3;
				}

				bool isok = 1;
				for (int ind = 1; ind <= m; ind++) {
					if (nowa[ind] == 2 || map[i][ind] == 2) {
						if (nowa[ind] != map[i][ind]) {
							isok = 0;
						}
					}
				}

				// if (now == 4) {
				// 	for (int j = 1; j <= 3; j++) {
				// 		std::cerr << nowa[j] << '\n';
				// 	}
				// }

				for (int l = 1; l <= m; l++) {
					for (int r = l + 1; r <= m; r++) {
						if (nowa[l] == 1 && nowa[r] == 1) {
							bool pass = 0;
							for (int j = l + 1; j <= r - 1; j++) {
								if (nowa[j] == 2) {
									pass = 1;
								}
							} 
							if (pass == 0) {
								isok = 0;
							}
						}
					}	
				}

				for (int ind = 1; ind <= m; ind++) {
					if (prea[ind] == 1 && nowa[ind] == 1) {
						isok = 0;
					}
				}

				if (isok == 0) {
					continue;
				}

				int merges = 0, base = 1;
				for (int ind = 1; ind <= m; ind++) {
					int th = 0;
					if (nowa[ind] == 1 || (nowa[ind] == 0 && prea[ind] == 1)) {
						th = 1;
					} else if (nowa[ind] == 2 || (nowa[ind] == 0 && prea[ind] == 2)) {
						th = 2;
					}
					merges += base * th;
					base *= 3;
				}

				dp[i][merges] = std::max(dp[i][merges], cntn + dp[i - 1][pre]);
				// std::cerr << now << " " << "dp" << " " << i << " " << merges << " = " << dp[i][merges] << '\n';
			}
		}
	}

	int ans = 0;
	for (int sit = 0; sit < maxs; sit++) {
		ans = std::max(ans, dp[n][sit]);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}