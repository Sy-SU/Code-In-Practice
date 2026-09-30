#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a[3];

	for (int i = 0; i < 3; i++) {
		std::cin >> a[i];
	}

	std::sort(a, a + 3);

	if (a[2] - a[0] <= 1) {
		std::cout << "YES" << '\n';
	} else {
		std::cout << "NO" << '\n';
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