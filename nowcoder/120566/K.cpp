#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 m, n, z;
	std::cin >> m >> n >> z;

	z %= (m + n);
	if (z > 0 && z <= m) {
		std::cout << 0;
	} else {
		std::cout << 1;
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