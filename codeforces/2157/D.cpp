#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, l, r;
	std::cin >> n >> l >> r;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	std::vector<int> s(n + 1);

	for (int i = 1; i <= n; i++) {
		if (a[i] < l) {
			s[i] = 1;
		} else if (a[i] > r) {
			s[i] = -1;
		} else {
			if (i <= n / 2) {
				s[i] = 1;
			} else if (i >= n - n / 2 + 1) {
				s[i] = -1;
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << s[i] << " \n"[i == n];
	// }

	// int res = a[lo + len / 2 - 1];
	i64 ans = 1e18;
	std::vector<int> canr;
	canr.push_back(l), canr.push_back(r);
	for (auto res : canr) {
		i64 tans = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == 0) {
				continue;
			}
			if (s[i] > 0) {
				tans += res - a[i];
			} else {
				tans += a[i] - res;
			}
		}
		ans = std::min(ans, tans);
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