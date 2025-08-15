#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> maxpre(n + 2, 0), maxsuf(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) {
			maxpre[i] = maxpre[i - 1] + a[i];
		} else {
			maxpre[i] = maxpre[i - 1];
		}
	}
	for (int i = n; i >= 1; i--) {
		if (a[i] < 0) {
			maxsuf[i] = maxsuf[i + 1] - a[i];
		} else {
			maxsuf[i] = maxsuf[i + 1];
		}
	}

	i64 ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = std::max(ans, maxpre[i] + maxsuf[i + 1]);
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