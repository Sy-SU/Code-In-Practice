#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	int x = n % 3;
	if (x == 0) {
		std::cout << 0 << '\n';
	} else {
		std::cout << 3 - x << '\n';
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