#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> c(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += c[i];
	}

	if (sum < 3) {
		std::cout << 0 << '\n';
		return;
	}

	i64 single = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 1) {
			single++;
		}
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i] > 1) {
			if (single == n - 1) {
				ans += c[i];
				i64 add = std::min(single, c[i] / 2);
				ans += add, single -= add;
			} else {
				ans += c[i];
				i64 add = std::min(single, c[i] / 2 - 1);
				ans += add, single -= add;
			}
		}
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