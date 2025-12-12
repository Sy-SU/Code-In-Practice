#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x, y, z;
	std::cin >> x >> y >> z;

	if (x >= y * z && (x - y * z) % (z - 1) == 0) {
		std::cout << "Yes" << '\n';
	} else {
		std::cout << "No" << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}