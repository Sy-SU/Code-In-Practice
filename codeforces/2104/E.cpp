#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string str;
	std::cin >> str;
	str = " " + str;

	std::vector<std::vector<int>> next(30, std::vector<int>(n + 2, 1e7));
	for (int i = n - 1; i >= 0; i--) {
		for (int ch = 1; ch <= k; ch++) {
			next[ch][i] = (str[i + 1] == ('a' + ch - 1) ? (i + 1) : next[ch][i + 1]);
		}
	}

	// for (int c = 1; c <= k; c++) {
	// 	for (int i = 1; i <= n; i++) {
	// 		std::cerr << next[c][i] << " \n"[i == n];
	// 	}
	// }

	std::vector<int> ans(n + 2, 1e9);
	ans[n + 1] = 1;
	for (int i = n; i >= 1; i--) {
		// i + 1 ~ n

		for (int ch = 1; ch <= k; ch++) {
			if (next[ch][i] == 1e7) {
				ans[i] = std::min(ans[i], 1 + (ch == (str[i] - 'a' + 1)));
			} else {
				ans[i] = std::min(ans[i], ans[next[ch][i]] + 1);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cerr << ans[i] << " \n"[i == n];
	}

	int q;
	std::cin >> q;
	while (q--) {
		std::string t;
		std::cin >> t;
		int m = t.size();
		t = " " + t;

		int now = 0;
		for (int i = 1; i <= m; i++) {
			if (now == 1e7) {
				break;
			}
			now = next[t[i] - 'a' + 1][now];
		}

		if (now == 1e7) {
			std::cout << 0 << '\n';
		} else {
			std::cout << ans[now + 1] << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}