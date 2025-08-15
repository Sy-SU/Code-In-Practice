#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::string s;
	std::cin >> s;

	std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1, 0)), p(n + 1, std::vector<i64>(m + 1, 0)), isok(n + 1, std::vector<i64>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}

	std::vector<i64> sumi(n + 1, 0), sumj(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sumi[i] += a[i][j];
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			sumj[j] += a[i][j];
		}
	}

	int nx = 1, ny = 1;
	p[1][1] = 1;
	i64 sum = 0;
	if (s[0] == 'D') {
		for (int j = 1; j <= m; j++) {
			sum += a[1][j];
		}
	} else {
		for (int i = 1; i <= n; i++) {
			sum += a[i][1];
		}
	}

	for (int d = 0; d < n + m - 2; d++) {
		char now = s[d];
		
		if (now == 'D') {
			nx++;
		} else {
			ny++;
		}

		if (d == n + m - 3) {
			i64 tsuma_d = 0, tsump_d = 0;
			for (int j = 1; j <= m; j++) {
				tsuma_d += a[nx][j], tsump_d += p[nx][j];
			}

			i64 tsuma_r = 0, tsump_r = 0;
			for (int i = 1; i <= n; i++) {
				tsuma_r += a[i][ny], tsump_r += p[i][ny];
			}

			a[nx][ny] = sum - tsuma_d, p[nx][ny] = p[1][1] - tsump_d;

			if (tsump_d == tsump_r) {
				assert(tsuma_d == tsuma_r);
				a[1][1] = 0;
			} else {
				a[1][1] = (tsuma_r - tsuma_d) / (tsump_d - tsump_r);
			}

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (i == 1 && j == 1) {
						continue;
					}
					a[i][j] += p[i][j] * a[1][1];
				}
			}
			break;
		}

		i64 tsump = 0, tsuma = 0;
		if (s[d + 1] == 'D') {
			for (int j = 1; j <= m; j++) {
				tsuma += a[nx][j], tsump += p[nx][j];
			}
		} else {
			for (int i = 1; i <= n; i++) {
				tsuma += a[i][ny], tsump += p[i][ny];
			}
		}
		a[nx][ny] = sum - tsuma, p[nx][ny] = p[1][1] - tsump;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cout << a[i][j] << " \n"[j == m];
		}
	}

	// i64 checksum = 0;
	// for (int i = 1; i <= n; i++) {
	// 	checksum += a[i][1];
	// }

	// for (int i = 1; i <= n; i++) {
	// 	i64 tcheck = 0;
	// 	for (int j = 1; j <= m; j++) {
	// 		tcheck += a[i][j];
	// 	}
	// 	assert(tcheck == checksum);
	// }
	// for (int j = 1; j <= m; j++) {
	// 	i64 tcheck = 0;
	// 	for (int i = 1; i <= n; i++) {
	// 		tcheck += a[i][j];
	// 	}
	// 	assert(tcheck == checksum);
	// }
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