#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr double eps = 1e-6;

void solve() {
	int n;
	i64 p;
	std::cin >> n >> p;
	i64 suma = 0, sumb = 0;
	std::vector<i64> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a[i] >> b[i];
		suma += a[i], sumb += b[i];
	}

	if (suma <= p) {
		std::cout << -1 << '\n';
		return;
	}

	double lo = 0, hi = 1e18;
	double ans = 0;
	while (hi - lo >= eps) {
		double mid = (lo + hi) / 2;

		auto check = [mid, &a, &b, n, p]() -> bool {
			double sum = 0;
			for (int i = 1; i <= n; i++) {
				sum += std::max(0.0, a[i] * mid - b[i]);
			}
			return sum <= mid * p;
		};

		if (check()) {
			lo = mid;
			ans = mid;
		} else {
			hi = mid;
		}
	}

	std::cout << std::fixed << std::setprecision(10) << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}