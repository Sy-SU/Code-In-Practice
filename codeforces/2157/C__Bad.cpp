#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k, q;
	std::cin >> n >> k >> q;

	std::vector<int> a(n + 1, -1);

	std::vector<std::pair<int, int>> min, mex;

	for (int qi = 1; qi <= q; qi++) {
		int c, l, r;
		std::cin >> c >> l >> r;

		if (c == 1) {
			min.push_back({l, r});
		} else {
			mex.push_back({l, r});
		}
	}

	for (auto [l, r] : min) {
		for (int i = l; i <= r; i++) {
			a[i] = k;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << a[i] << " \n"[i == n];
	// }

	for (auto [l, r] : mex) {
		std::vector<int> vis(k);
		for (int i = l; i <= r; i++) {
			if (a[i] == k) {
				a[i] = 1e9;
			}			
			if (a[i] < 0 || a[i] >= k) {
				continue;
			}
			vis[a[i]] = 1;
		}

		int now = 0;
		for (int i = l; i <= r; i++) {
			if (a[i] == -1) {
				while (now < k && vis[now]) {
					now++;
				}
				if (now >= k) {
					break;
				}
				a[i] = now, vis[now] = 1;
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << a[i] << " \n"[i == n];
	// }

	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) {
			a[i] = 1e9;
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << a[i] << " \n"[i == n];
	}

	// checker 
	// for (int i = 1; i <= n; i++) {
	// 	// assert(a[i] >= 0 && a[i] <= 1e9);
	// }
	// for (auto [l, r] : min) {
	// 	int min = 1e9;
	// 	for (int i = l; i <= r; i++) {
	// 		min = std::min(min, a[i]);
	// 	}
	// 	assert(min == k);
	// }
	// for (auto [l, r] : mex) {
	// 	std::vector<int> cnt(k + 1);
	// 	for (int i = l; i <= r; i++) {
	// 		if (a[i] >= 0 && a[i] <= k) {
	// 			cnt[a[i]]++;
	// 		}
	// 	}
	// 	for (int i = 0; i < k; i++) {
	// 		assert(cnt[i]);
	// 	}
	// 	assert(cnt[k] == 0);
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