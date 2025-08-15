#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	if (n == 2) {
		std::cout << 1 << " " << 2 << '\n';
		return;
	}

	if (n == 3) {
		std::cout << 1 << " " << 2 << '\n';
		std::cout << 2 << " " << 3 << '\n';
		return;
	}

	if (n == 4) {
		std::cout << -1 << '\n';
		return;
	}

	int res = (n - 3) / 2;
	for (int i = 1; i < n - res; i++) {
		std::cout << i << " " << i + 1 << '\n';
	}
	for (int i = 2; i <= res + 1; i++) {
		std::cout << i << " " << n - res + i - 1 << '\n';
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