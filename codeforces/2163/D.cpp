#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> r(n + 1), l(n + 1, 1e9);
	for (int i = 1; i <= q; i++) {
		int x, y;
		std::cin >> x >> y;

		r[x] = std::max(r[x], y), l[y] = std::min(l[y], x);
	}

	int lo = 1, hi = n / 2;

	std::cout << "? " << 1 << " " << n / 2 << std::endl;
	int res;
	std::cin >> res;

	if (res == 0) {
		lo = n / 2, hi = n;
	}

	int ans = 0;
	if (lo == 1) {
		for (int i = lo; i <= hi; i++) {
			if (r[i] < 1) {
				continue;
			}
			std::cout << "? " << i << " " << r[i] << std::endl;
			std::cin >> res;

			ans = std::max(ans, res);
		}
	} else {
		for (int i = lo; i <= hi; i++) {
			if (l[i] > n) {
				continue;
			}
			std::cout << "? " << l[i] << " " << i << std::endl;
			std::cin >> res;

			ans = std::max(ans, res);
		}
	}

	std::cout << "! " << ans << std::endl;
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