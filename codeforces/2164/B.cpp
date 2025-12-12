#include <bits/stdc++.h>

using i64 = long long;

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

int rng(int l, int r) { // [l, r]
	return rnd() % (r - l + 1) + l;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> even;
	for (int i = 1; i <= n; i++) {
		if (a[i] % 2 == 0) {
			even.push_back(i);
		}
	}

	if (even.size() >= 2) {
		std::cout << a[even[0]] << " " << a[even[1]] << '\n';
		return;
	}

	if (even.size() == 1) {
		for (int i = 1; i < even[0]; i++) {
			int x = a[i], y = a[even[0]];
			int m = y % x;
			if (m % 2 == 0) {
				std::cout << x << " " << y << '\n';
				return;
			}
		}

		std::vector<int> b;
		b.push_back(0);
		for (int i = 1; i <= n; i++) {
			if (i != even[0]) {
				b.push_back(a[i]);
			}
		}

		n--;
		a = b;
	}

	if (n <= 1000) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int m = a[j] % a[i];
				if (m % 2 == 0) {
					std::cout << a[i] << " " << a[j] << '\n';
					return;
				}
			}
		}
		std::cout << -1 << '\n';
		return;
	}

	int t = 1000000;
	while (t--) {
		int i = rng(1, n), j = rng(1, n);
		if (i == j) {
			continue;
		}
		if (i > j) {
			std::swap(i, j);
		}

		int m = a[j] % a[i];
		if (m % 2 == 0) {
			std::cout << a[i] << " " << a[j] << '\n';
			return;
		}
	}
	std::cout << -1 << '\n';
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