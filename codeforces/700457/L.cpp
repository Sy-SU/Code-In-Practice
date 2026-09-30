#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(n);
	for (int i = 1; i < n; i++) {
		std::cin >> b[i];
	}

	bool dizeng = 1, dijian = 1;
	for (int i = 2; i < n; i++) {
		if (b[i] < b[i - 1]) {
			dizeng = 0;
		} else {
			dijian = 0;
		}
	}

	if (dizeng) {
		for (int i = 1; i < n; i++) {
			std::cout << i + 1 << " ";
		}
		std::cout << 1 << '\n';
		return;
	}

	if (dijian) {
		std::cout << n << " ";
		for (int i = 2; i <= n; i++) {
			std::cout << i - 1 << " \n"[i == n];
		}
		return;
	}

	std::cout << -1 << '\n';

	// std::vector<int> p(n);
	// for (int i = 0; i < n; i++) {
	// 	// std::cin >> p[i];
	// 	p[i] = i + 1;
	// }

	// do {
	// 	std::vector<int> premax(n + 2), sufmin(n + 2, 1e9);
	// 	for (int i = 1; i <= n; i++) {
	// 		premax[i] = std::max(premax[i - 1], p[i - 1]);
	// 	}
	// 	for (int i = n; i >= 1; i--) {
	// 		sufmin[i] = std::min(sufmin[i + 1], p[i - 1]);
	// 	}

	// 	bool isok = 1;
	// 	for (int i = 1; i < n; i++) {
	// 		if (premax[i] - sufmin[i + 1] != b[i]) {
	// 			isok = 0;
	// 		}
	// 	}

	// 	if (isok) {
	// 		for (int i = 0; i < n; i++) {
	// 			std::cout << p[i] << " \n"[i == n - 1];
	// 		}
	// 	}
	// } while (std::next_permutation(p.begin(), p.end()));

	// std::cout << "F" << '\n';
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