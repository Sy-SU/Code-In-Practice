#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;

		sum += std::max(1, x);
	}
	std::cout << sum << '\n';
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