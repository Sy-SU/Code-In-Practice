#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = 2; i <= n; i++) {
		if (std::abs(a[i] - a[i - 1]) <= 1) {
			std::cout << 0 << '\n';
			return;
		}
	}

	bool isok1 = 1, isok2 = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i - 1]) {
			isok2 = 0;
		}
		if (a[i] < a[i - 1]) {
			isok1 = 0;
		}
	}

	if (isok1 || isok2) {
		std::cout << -1 << '\n';
	} else {
		std::cout << 1 << '\n';
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