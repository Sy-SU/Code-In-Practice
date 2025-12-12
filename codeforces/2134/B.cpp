#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			a[i] += (a[i] % 2);
		}
	} else if (k == 2) {
		for (int i = 1; i <= n; i++) {
			if (a[i] % 3 == 1) {
				a[i] += 2;
			} else if (a[i] % 3 == 2) {
				a[i] += 4;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			i64 m = a[i] % (k - 1);
			a[i] += k * ((k - 1) - m);
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << a[i] << " \n"[i == n];
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