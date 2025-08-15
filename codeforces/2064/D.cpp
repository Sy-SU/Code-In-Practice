#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> w(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}


	// std::vector<std::vector<int>> lstw(50, std::vector<int>(2, -1));
	// lst[i][0/1] 表示第 i 位从右往左第一个对应 bit 为 0/1 的 ind

	// for (int i = 1; i <= n; i++) {
	// 	for (int b = 0; b <= 30; b++) {
	// 		lstw[b][(w[i] >> b) & 1] = i;
	// 	}
	// }

	std::vector<int> suf(n + 2, 0);
	for (int i = n; i >= 1; i--) {
		suf[i - 1] = suf[i] ^ w[i];
	}

	// std::vector<std::vector<int>> lstsuf(50, std::vector<int>(2, -1));
	// lst[i][0/1] 表示第 i 位从右往左第一个对应 bit 为 0/1 的 ind

	// for (int i = 1; i <= n; i++) {
	// 	for (int b = 0; b <= 30; b++) {
	// 		lstsuf[b][(suf[i] >> b) & 1] = i;
	// 	}
	// }

	std::map<std::pair<int, int>, int> lst[50];
	for (int b = 0; b <= 30; b++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				lst[b][{i, j}] = 0;
			}
		}
	}
	for (int b = 0; b <= 30; b++) {
		for (int i = 1; i <= n; i++) {
			lst[b][{(suf[i] >> b) & 1, (w[i] >> b) & 1}] = i;
		}
	}

	auto dfs = [&](auto &&self, int x, int b, bool tag) -> int {
		if (b == -1) {
			return 0;
		}
		int now = (x >> b) & 1;
		for (int bs = 0; bs < 2; bs++) {
			for (int bw = 0; bw < 2; bw++) {
				int lstind = lst[b][{bs, bw}];
				if (now == 0 && bs == 0 && bw == 1) {
					if (tag == 0) {
						return n;
					} else {
						return 0;
					}
				} else if (now == 1 && bs == 1 && bw == 1) {
					if (tag == 0) {
						return n;
					} else {
						return 0;
					}					
				}
				// <

				if (now == 0 && bs == 1 && bw == 0) {
					return std::max(lstind, self(self, x, b - 1, 1));
				} else if (now == 1 && bs == 0 && bw == 0) {
					return std::max(lstind, self(self, x, b - 1, 1));
				}
				// >

				if (now == 0 && bs == 0 && bw == 0) {
					return std::max(lstind, self(self, x, b - 1, tag));
				} else if (now == 0 && bs == 1 && bw == 1) {
					return std::max(lstind, self(self, x, b - 1, tag));
				} else if (now == 1 && bs == 0 && bw == 1) {
					return std::max(lstind, self(self, x, b - 1, tag));
				} else if (now == 1 && bs == 1 && bw == 0) {
					return std::max(lstind, self(self, x, b - 1, tag));
				}
				// =
			}
		}
	};

	while (q--) {
		int x;
		std::cin >> x;

		std::cout << n - dfs(dfs, x, 30, 0) << " \n"[q == 0];
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