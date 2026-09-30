#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, x, y, z;
	std::cin >> n >> x >> y >> z;

	i64 ans1 = (n + x + y - 1) / (x + y);
	i64 ans2 = z + (n - x * z + x + 10 * y - 1) / (x + 10 * y);

	if (n > x * z) {
		ans1 = std::min(ans1, ans2);
	}

	std::cout << ans1 << '\n';
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