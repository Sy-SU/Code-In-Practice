#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	int k;
	std::cin >> n >> k;

	if (k % 2) {
		for (int i = 1; i <= k; i++) {
			std::cout << n << " \n"[i == k];
		}
		// std::cout << n * k << "\n";
		return;
	}

	std::vector<int> a(k + 1, n);
	std::vector<std::vector<int>> ans(k + 1, std::vector<int>(31));
	int safe = 0;
	for (int b = 30; b >= 0; b--) {
		int tb = (n >> b) & 1;
		if (tb) {
			// 1 ~ safe, safe + 1 ~ k
			if (safe < k) {
				// safe + 1
				for (int i = 1; i <= k; i++) {
					if (i == safe + 1) {
						ans[i][b] = 0;
					} else {
						ans[i][b] = 1;
					}
				}
				safe++;
			} else {
				for (int i = 1; i <= k; i++) {
					// a[i][b] = 1
					if (i == k) {
						ans[i][b] = 0;
					} else {
						ans[i][b] = 1;
					}
				}
			}
		} else {
			if (safe < k) {
				int l = 0;
				while (l + 2 <= safe) {
					l += 2;
				}
				for (int i = 1; i <= k; i++) {
					if (i <= l) {
						ans[i][b] = 1;
					} else {
						ans[i][b] = 0;
					}
				}
			} else {
				for (int i = 1; i <= k; i++) {
					ans[i][b] = 1;
				}
			}
		}
	}

	std::vector<i64> c(k + 1);
	for (int i = 1; i <= k; i++) {
		for (int b = 0; b <= 30; b++) {
			c[i] += (1 << b) * ans[i][b];
		}
	}

	i64 sum = 0, xsum = 0;
	for (int i = 1; i <= k; i++) {
		std::cout << c[i] << " \n"[i == k];
		sum += c[i], xsum ^= c[i];
	}
	// std::cout << sum << " " << xsum << "\n";
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