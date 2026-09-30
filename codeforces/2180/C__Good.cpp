#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	int k;
	std::cin >> n >> k;

	std::vector<i64> ans;
	i64 maxsum = 0;

	i64 sta = pow(n + 1, k);
	for (i64 s = 0; s < sta; s++) {
		i64 now = s;
		std::vector<i64> a(k + 1);
		for (int i = 1; i <= k; i++) {
			a[i] = now % (n + 1);
			now /= (n + 1);
		}

		i64 sum = 0, xsum = 0;
		for (int i = 1; i <= k; i++) {
			sum += a[i], xsum ^= a[i];
		}
		if (xsum == n) {
			if (sum >= maxsum) {
				ans = a;
				maxsum = sum;
			}
		}
	}

	// for (int i = 1; i <= k; i++) {
	// 	std::cout << ans[i] << " \n"[i == k];
	// }

	std::cout << maxsum << '\n';
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