#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	for (int i = 1; i <= 100000; i++) {
		std::cout << i + 1 << " " << 2 * i +  1 << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}