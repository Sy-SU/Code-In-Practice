#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j];
		}
	}

	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += a[i][j];
		}
	}

	if (sum % (n * n)) {
		std::cout << "No" << '\n';
		return;
	}

	sum /= (n * n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] -= sum;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int c = a[i][j];
			a[i][j] -= c, a[i + 1][j + 1] += c;
			a[i][j + 1] += c, a[i + 1][j] -= c;
		}
		if (a[i][n] != 0) {
			i64 d = a[i][n] / 2;
			a[i][n] -= 2 * d, a[i + 1][n - 1] += 2 * d;
		}
	}

	for (int j = 1; j < n; j++) {
		for (int i = 1; i < n; i++) {
			int c = a[i][j];
			a[i][j] -= c, a[i + 1][j + 1] += c;
			a[i][j + 1] -= c, a[i + 1][j] += c;
		}
		if (a[n][j] != 0) {
			i64 d = a[n][j] / 2;
			a[n][j] -= 2 * d, a[n - 1][j + 1] += 2 * d;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		std::cout << a[i][j] << " \n"[j == n];
	// 	}
	// }

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != 0) {
				std::cout << "No" << '\n';
				return;
			}
		}
	}
	std::cout << "Yes" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}