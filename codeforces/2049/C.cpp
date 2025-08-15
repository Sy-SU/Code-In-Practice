#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, x, y;
	std::cin >> n >> x >> y;

	std::vector<int> ans(n + 1, -1);

	if (std::abs(x - y) != 1 && std::abs(x - y) != n - 1) {
		// x -> y

		ans[x] = 0, ans[y] = 1;
		for (int i = y - 1; i >= x + 1; i--) {
			ans[i] = (ans[i + 1] + 1) % 3;
		}

		if (ans[x + 1] == 0) {
			ans[x + 1] = 1;
			ans[x + 2] = 0;
		}

		// y + 1 -> n -> 1 -> x
		for (int i = y + 1; i <= n; i++) {
			ans[i] = (ans[i - 1] + 1) % 3;
		}
		ans[0] = ans[n];
		for (int i = 1; i <= x - 1; i++) {
			ans[i] = (ans[i - 1] + 1) % 3;
		}

		if (x != 1 && ans[x - 1] == 0) {
			ans[x - 1] = 1;
			if (x != 2) {
				ans[x - 2] = 0;
			} else {
				ans[n] = 0;
			}
		}
		if (x == 1 && ans[n] == 0) {
			ans[n] = 1;
			ans[n - 1] = 0;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			ans[i] = (ans[i - 1] + 1) % 3;
		}
		if (ans[n] == 0) {
			ans[n] = 1;
			ans[n - 1] = 0;
		}
	}

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