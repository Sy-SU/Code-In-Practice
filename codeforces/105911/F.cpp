#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<double> r(n + 1, -1), c(n + 1);
	double p, L, R;

	std::cin >> r[0] >> c[0] >> p >> L >> R;
	for (int i = 1; i <= k; i++) {
		int pos;
		double v;
		std::cin >> pos >> v;

		r[pos] = v;
	}

	double ans = c[0] * p * (1 - pow(p, n)) / (1 - p);
	for (int i = 1; i < n; i++) {
		if (r[i] == -1) {
			r[i] = L;
		}
		ans -= pow(p, n - i) * r[i];
	}
	if (r[n] == -1) {
		r[n] = L;
	}
	ans += r[0] * (1 - pow(p, n)) - r[n];

	std::cout << std::fixed << std::setprecision(10) << ans << '\n';
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