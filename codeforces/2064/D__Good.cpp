#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<i64> w(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}

	std::vector<i64> suf(n + 2, 0);
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] ^ w[i];
	}

	std::vector<std::vector<int>> lstbit(50, std::vector<int>(2, -1));
	// lstbit[i][0/1] 表示第 i 位从右往左第一个对应 bit 为 0/1 的 ind

	for (int i = 1; i <= n; i++) {
		for (int b = 0; b <= 30; b++) {
			lstbit[b][(w[i] >> b) & 1] = i;
		}
	}

		for (int b = 0; b <= 3; b++) {
			std::cerr << lstbit[b][0] << " " << lstbit[b][0] << '\n';
		}
	

	while (q--) {
		i64 x;
		std::cin >> x;

		int lst = n + 1;
		for (int i = n; i >= 1; i--) {
			if ((x ^ suf[i + 1]) >= w[i]) {
				lst = i;
			} else {
				break;
			}
		}
		std::cout << n - lst + 1 << " \n"[q == 0];
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