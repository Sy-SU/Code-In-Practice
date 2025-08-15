#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	int mininv = 1e9;
	std::vector<int> best;

	int maxs = (1 << (n - 1));
	for (int s = 0; s < maxs; s++) {
		int nows = s;

		std::vector<int> tmp(n + 1);
		for (int i = 1; i <= n; i++) {
			tmp[i] = (nows % 2 ? p[i] : 2 * n - p[i]);
			nows /= 2;
		}

		int inv = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				inv += (tmp[i] > tmp[j]);
			}
		}

		if (mininv > inv) {
			mininv = inv;
			best = tmp;
		}
	}

	std::cout << mininv << '\n';

	// std::cerr << "best ans : " << mininv << '\n';
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << best[i] << " \n"[i == n];
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