#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> p1(n + 1), p2(n + 1), p3(n + 1);
	for (int i = 1; i <= n; i++) {
		p1[i] = p1[i - 1] + (a[i] == 1);
		p2[i] = p2[i - 1] + (a[i] == 2);
		p3[i] = p3[i - 1] + (a[i] == 3);
	}

	std::vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		v[i] = p3[i] * 2 - i;
		// std::cerr << p3[i] << " " << v[i] << "\n";
	}

	std::vector<int> sufmin(n + 2, 1e9);
	for (int i = n - 1; i >= 1; i--) {
		sufmin[i] = std::min(sufmin[i + 1], v[i]);
	}

	// for (int i = 1; i <= n; i++) std::cerr << sufmin[i] << " \n"[i == n];

	for (int i = 1; i <= n; i++) {
		if (p1[i] * 2 < i) {
			continue;
		}

		if (v[i] >= sufmin[i + 1]) {
			// std::cerr << i << " " << v[i] << " " << sufmin[i + 1] << '\n';
			std::cout << "YES" << '\n';
			return;
		}
	}
	std::cout << "NO" << '\n';
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