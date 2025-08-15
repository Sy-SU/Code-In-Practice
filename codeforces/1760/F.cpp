#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, d;
	i64 c;
	std::cin >> n >> c >> d;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end(), std::greater<i64>());

	std::vector<i64> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	i64 lo = 0, hi = 2 * d;
	i64 ans = -1;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&](i64 x) -> bool {
			x++;
			i64 del = d / x, res = d % x;
			i64 sum = del * pre[std::min(x, n * 1ll)] + pre[std::min(res, n * 1ll)];
			return sum >= c;
		};

		if (check(mid)) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}

	if (ans == -1) {
		std::cout << "Impossible" << '\n';
	} else if (ans > d) {
		std::cout << "Infinity" << '\n';
	} else {
		std::cout << ans << '\n';
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