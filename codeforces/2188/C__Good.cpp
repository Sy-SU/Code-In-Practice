#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	auto b = a;
	std::sort(b.begin() + 1, b.end());

	std::vector<int> c;
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			c.push_back(b[i]);
		}
	}

	int k = 2e9;
	for (int i = 1; i < (int)c.size(); i++) {
		int A = c[i - 1], B = c[i];
		if (A == B) {
			continue;
		}
		// std::cerr << A << " " << B << '\n';

		k = std::min(k, std::max({B - A, A - b[1], b[n] - B}));
	}

	if (k > 1e9) {
		k = -1;
	}
	std::cout << k << "\n";

	// int premax = 0;
	// int l = 1e9, r = 0;
	// for (int i = 1; i <= n; i++) {
	// 	if (a[i] < premax) {
	// 		l = std::min(l, a[i]);
	// 		r = std::max(r, premax);
	// 	}

	// 	premax = std::max(premax, a[i]);
	// }

	// std::sort(a.begin() + 1, a.end());

	// std::cerr << l << " " << r << '\n';

	// int k = 2e9;
	// for (int i = 2; i <= n; i++) {
	// 	int A = a[i - 1], B = a[i];
	// 	if (A == B || A < l || B > r) {
	// 		continue;
	// 	}

	// 	k = std::min(k, std::max({B - A, A - a[1], a[n] - B}));
	// }

	// if (k > 1e9) {
	// 	k = -1;
	// }
	// std::cout << k << "\n";
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