#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}
	if (sum % 2) {
		std::cout << "YES" << '\n';
		return;
	}

	if (n * k % 2 == 0) {
		std::cout << "YES" << '\n';
		return;
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