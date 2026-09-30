#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	std::vector<i64> a(n + 1), c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	for (int i = 2; i <= n; i++) {
		if (c[i] < c[i - 1]) {
			std::cout << "NO" << '\n';
			return;
		}
	}

	std::vector<int> fix(n + 1);
	for (int i = 1; i <= n; i++) {
		if (i == 1 || c[i] != c[i - 1]) {
			fix[i] = 1;
		}
	}

	// 如果 fix[i] == 1, 那么 pre[i] = c[i]
	// std::vector<i64> pre(n + 1);
	// for (int i = 1; i <= n; i++) {
	// 	int tag = s[i - 1] == '1';
	// 	if (tag) {
	// 		pre[i] = pre[i - 1] + a[i];
	// 	} else {
	// 		if (fix[i] == 1) {

	// 		}
	// 	}
	// }

	std::vector<i64> lo(n + 1, -1e15), hi(n + 1, 1e15);
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '1') {
			if (i == 1) {
				lo[i] = hi[i] = a[i];
			} else {
				lo[i] = lo[i - 1] + a[i];
				hi[i] = hi[i - 1] + a[i];
			}

			// std::cerr << "i = " << i << " " << lo[i] << " " << hi[i] << '\n';
			
			if (i == 1 && (c[i] < lo[i] || c[i] > hi[i])) {
				std::cout << "NO" << '\n';
				return;
			}
		}
		if (fix[i]) {
			lo[i] = hi[i] = c[i];
		} else {
			hi[i] = std::min(hi[i], c[i]);
		}
// std::cerr << "i = " << i << " " << lo[i] << " " << hi[i] << '\n';
		if (lo[i] > hi[i]) {
			std::cout << "NO" << '\n';
			return;
		}
	}

	
	std::vector<i64> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '1') {
			ans[i] = a[i];
		} else {
			ans[i] = lo[i] - a[i - 1];
		}
	}

	std::cout << "YES" << '\n';
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << " \n"[i == n];
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