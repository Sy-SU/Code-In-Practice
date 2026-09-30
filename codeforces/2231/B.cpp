#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	a[n + 1] = 1e18;

	std::vector<int> p;

	i64 mind = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] > a[i]) {
			if (a[i] > a[i + 1]) {
				std::cout << "NO" << "\n";
				return;
			}

			p.push_back(i); // a[i - 1] > a[i]
			mind = std::max(mind, a[i - 1] - a[i]);
		}
	}

	for (int i = 1; i < (int)p.size(); i++) {
		bool isok = 0;
		int l = p[i - 1] + 1, r = p[i] - 1;
		// std::cerr << l << " " << r << " " << mind << '\n';
		for (int j = l; j <= r; j++) {
			if (a[j] - a[j - 1] >= mind) {
				isok = 1;
			}
		}
		if (isok == 0) {
			std::cout << "NO" << '\n';
			return;
		}
	}
	std::cout << "YES" << '\n';
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