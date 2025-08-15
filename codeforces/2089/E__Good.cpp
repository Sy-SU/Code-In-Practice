#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> a(n), b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	int epoch = 0;
	while (1) {
		bool isok = 1;
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				isok = 0;
				break;
			}
		}
		if (isok) {
			break;
		}
		for (int i = 0; i < n; i++) {
			int m = std::min(a[i], b[i]);
			a[i] -= m, b[i] -= m;
		}
		int lst = a[n - 1];
		for (int i = n - 1; i >= 1; i--) {
			a[i] = a[i - 1];
		}
		a[0] = lst;
		epoch++;
		// for (int i = 0; i < n; i++) {
		// 	std::cerr << a[i] << " \n"[i == n - 1];
		// }
		// for (int i = 0; i < n; i++) {
		// 	std::cerr << b[i] << " \n"[i == n - 1];
		// }
		// std::cerr << '\n';
	}
	std::cout << epoch << '\n';
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