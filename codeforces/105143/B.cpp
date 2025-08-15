#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n;
	std::cin >> n;

	std::vector<i64> a(n + 1), need(60, 0), pw(60, 0);
	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}

	pw[0] = 1;
	for (int i = 1; i <= 50; i++) {
		pw[i] = pw[i - 1] * 2;
	}

	for (int b = 50; b >= 0; b--) {
		if ((pw[b] - 1) >= (sum + n - 1) / n) {
			continue;
		}
		need[b] = 1;
		if (sum >= pw[b] * n) {
			sum -= pw[b] * n;
		} else {
			i64 x = sum / pw[b];
			sum -= pw[b] * x;
			if (x == 0) {
				need[b] = 0;
			}
			assert((pw[b] - 1) * n >= sum);
		}
	}

	i64 ans = 0;
	for (int b = 0; b <= 50; b++) {
		ans += need[b] * pw[b];
	}
	std::cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}