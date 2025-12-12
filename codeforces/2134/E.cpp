#include <bits/stdc++.h>

using i64 = long long;

int cnt;

void swap(int x) {
	cnt++;
	std::cout << "swap " << x << std::endl;
}

int thr(int x) {
	cnt++;
	std::cout << "throw " << x << std::endl;
	int res;
	std::cin >> res;
	return res;
}

void solve() {
	int n;
	std::cin >> n;

	cnt = 0;

	std::vector<int> a(n + 1), ans(n + 1);
	int r = thr(n - 1);
	if (r == 1) {
		a[n - 1] = 2;
	} else if (r == 2) {
		a[n - 1] = 1;
	} else {
		assert(0);
	}

	swap(n - 1);
	r = thr(n - 1);
	if (r == 1) {
		a[n] = 2;
	} else if (r == 2) {
		a[n] = 1;
	} else {
		assert(0);
	}

	ans[n] = a[n], ans[n - 1] = a[n - 1];

	std::swap(a[n - 1], a[n]);

	std::vector<int> dp(n + 3);
	dp[n] = dp[n + a[n]] + 1, dp[n - 1] = dp[n - 1 + a[n - 1]] + 1;

	for (int i = n - 2; i >= 1; i--) {
		if (dp[i + 1] != dp[i + 2]) {
			r = thr(i);
			if (r == dp[i + 1] + 1) {
				a[i] = ans[i] = 1;
			} else {
				a[i] = ans[i] = 2;
			}
		} else {
			// a[i + 1] = 2
			int r1 = thr(i);
			swap(i);
			int r2 = thr(i);
			assert(r1 = dp[i + 3] + 1);
			if (r1 == r2) {
				// a[i] = 2;
				a[i] = 2;
				ans[i] = 2;
			} else {
				// a[i] = 1;
				a[i] = 1;
				ans[i] = 1;
			}
			std::swap(a[i], a[i + 1]);
			dp[i + 1] = dp[i + 1 + a[i + 1]] + 1;
			dp[i] = dp[i + a[i]] + 1;
		}
	}

	std::cout << "! ";
	for (int i = 1; i <= n; i++) {
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;
	assert(cnt <= (3 * n + 1) / 2);
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