#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	if (n == 2) {
		std::cout <<  << '\n';
		return;
	}

	std::vector<i64> a(60);
	a[1] = 1, a[2] = 2, a[3] = 3;
	i64 sum = 6;
	for (int i = 4; i <= n; i++) {
		a[i] = sum;
		sum += a[i];
	}

	for (int i = 1; i <= n; i++) {
		std::cout << a[i] << " \n"[i == n];
		// assert(a[n] <= 1e17);
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