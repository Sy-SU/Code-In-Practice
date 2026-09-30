#include <bits/stdc++.h>

using i64 = long long;

constexpr double eps = 1e-3;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> d(n + 1);
	for (int i = 1; i < n; i++) {
		d[i] = a[i + 1] - a[i];
	}
	d[n] = 1e10;

	int ans = 0;

	std::vector<double> l(n + 1), r(n + 1);
	l[1] = eps, r[1] = d[1] - eps;
	for (int i = 2; i <= n; i++) {
		// r[i] + r[i - 1] = d[i - 1]
		l[i] = d[i - 1] - r[i - 1];
		r[i] = d[i - 1] - l[i - 1];

		l[i] = std::max(eps, l[i]), r[i] = std::max(eps, r[i]);
		l[i] = std::min(l[i], d[i] - eps), r[i] = std::min(r[i], d[i] - eps);

		if (l[i] + l[i - 1] > d[i - 1]) {
			r[i] = d[i] - eps;
		} else if (r[i] + r[i - 1] < d[i - 1]) {
			r[i] = d[i] - eps;
		} else {
			ans++;
		}
		// std::cerr << std::setprecision(8) << l[i] << " " << r[i] << " " << ans << '\n';
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