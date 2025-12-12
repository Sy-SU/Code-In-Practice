#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	i64 max = 0, min = 0;
	for (int i = 1; i <= n; i++) {
		i64 nmax = std::max({max - a[i], min - a[i], b[i] - max, b[i] - min});
		i64 nmin = std::min({max - a[i], min - a[i], b[i] - max, b[i] - min});

		// std::cerr << max - a[i] << " " << min - a[i] << " " << b[i] - max << " " << b[i] - min << '\n';

		max = nmax, min = nmin;
		// std::cerr << max << " " << min << '\n';
	}

	std::cout << max << '\n';
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