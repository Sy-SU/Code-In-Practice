#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, x, y;
	std::cin >> n >> x >> y;

	// i64 ans = 0;
	// for (int i = 0; i <= y; i++) {
	// 	for (int j = 0; j <= i; j++) {
	// 		// std::cerr << i << " " << j << " " << (i - j + 1) * (j + 1) + (n - i) * (2 * x + 2 * j - n + i - 1) / 2 << '\n';
	// 		ans = std::max(ans, (i - j + 1) * (x + j) + (n - i) * (2 * x + 2 * j - n + i - 1) / 2);
	// 	}
	// }

	// for (int i = 0; i <= y; i++) {
	// 	// x + i
	// 	i64 sum = 0;
	// 	i64 att = x + i;
	// 	for (int r = i; r <= n; r++) {
	// 		sum += att;
	// 		att--;
	// 		if (att == 0) {
	// 			break;
	// 		}
	// 	}
	// 	ans = std::max(ans, sum);
	// }
	// std::cout << ans << '\n';

	int con = 1;
	for (int i = 1; i <= n; i++) {
		con *= 4;
	}
	i64 ans = 0;
	for (int cc = 0; cc < con; cc++) {
		int tmp = cc;

		i64 sum = 0;

		i64 nowx = x;

		i64 modao = 0;

		for (int i = 1; i <= n; i++) {
			if (tmp % 4 == 0) {
				modao++;
				if (modao > y) {
					break;
				}
				nowx++;
			} else if (tmp % 4 == 1) {
				modao++;
				if (modao > y) {
					break;
				}
				nowx++;

				sum += nowx;
				nowx--;
				if (nowx == 0) {
					break;
				}
			} else if (tmp % 4 == 2) {
				sum += nowx;
				nowx--;
				if (nowx == 0) {
					break;
				}
			}

			tmp /= 4;
		}

		ans = std::max(ans, sum);

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