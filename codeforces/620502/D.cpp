#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, x;
	std::cin >> n >> x;

	std::vector<int> c(n + 1);
	std::vector<i64> a(n + 1), d(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> d[i];
	}

	i64 lo = 1, hi = 1e15;
	i64 ans = -1;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&](i64 t) -> bool {
			i64 sum = 0;
			for (int i = 1; i <= n; i++) {
				i64 tmp = std::min(d[i], (t + c[i] - 1) / c[i]);
				if (tmp >=  (x + a[i] - 1) / a[i]) {
					return 1;
				}
				sum += std::min(d[i], (t + c[i] - 1) / c[i]) * a[i];
				if (sum >= x) {
					return 1;
				}
			}
			return sum >= x;
		};

		if (check(mid)) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
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