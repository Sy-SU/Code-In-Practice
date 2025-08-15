#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	i64 x, y;
	std::cin >> n >> x >> y;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	while (1) {
		for (int i = 1; i <= n; i++) {
			ans += (a[i] % 2) * x;
			a[i] -= (a[i] % 2);
		}

		i64 tmp = 0;
		for (int i = 1; i <= n; i++) {
			tmp += (a[i] - a[i] / 2);
		}

		if (tmp >= 1e18 / x) {
			tmp = 1e18 / x;
		}

		ans += std::min(tmp * x, y);

		for (int i = 1; i <= n; i++) {
			a[i] /= 2;
		}

		bool isok = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i]) {
				isok = 0;
			}
		}
		if (isok) {
			break;
		}
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}