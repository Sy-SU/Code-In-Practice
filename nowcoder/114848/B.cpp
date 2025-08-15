#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	if (k == n - 1) {
		std::cout << -1 << '\n';
		return;
	}

	for (int i = 1; i <= k; i++) {
		std::cout << i << " ";
	}
	for (int i = k + 1; i < n; i++) {
		std::cout << i + 1 << " ";
	}
	if (k != n) {
		std::cout << k << " ";
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}