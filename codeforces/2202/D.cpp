#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	if (n > k || k > 2 * n - 1) {
		std::cout << "NO" << '\n';
		return;
	}

	std::cout << "YES" << '\n';

	std::vector<int> a(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		a[i] = (i + 1) / 2;
	}

	// if (k == (3 * n + 1) / 2) {
	// 	for (int i = 1; i <= n; i++) {
	// 		a[i] = a[i + n] = i;
	// 	}
	// } else {
	// 	int d = k - n;
	// 	for (int i = 1; i <= d; i++) {
	// 		std::swap(a[4 * (i - 1) + 2], a[4 * (i - 1) + 3]);
	// 	}
	// }

	int d = k - n;

	if (d > 0) {
		int ind1 = 0, ind2 = 2;
		for (int i = 1; i <= 2 * d + 2; i += 2) {
			a[i] = ind1++;
			a[i + 1] = ind2++;
		}
		a[1] = 1;
		a[2 * d + 2] = d + 1;
		for (int i = 2 * d + 3; i <= 2 * n; i++) {
			a[i] = (i + 1) / 2;
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		std::cout << a[i] << " \n"[i == 2 * n];
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