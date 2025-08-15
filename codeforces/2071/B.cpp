#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	if (n == 1) {
		std::cout << -1 << '\n';
		return;
	}
	std::vector<i64> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		ans[i] = i;
	}
	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += ans[i];
		if ((i64)sqrt(sum) * (i64)sqrt(sum) == sum) {
			if (i == n) {
				std::cout << -1 << '\n';
				return;
			}
			sum -= ans[i], sum += ans[i + 1];
			std::swap(ans[i], ans[i + 1]);
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