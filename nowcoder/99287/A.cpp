#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int x, y;
	std::cin >> x >> y;
	if (x == 0) {
		std::cout << std::max(0, 2 * y - 1) << '\n';
		return;
	}
	int cnt = y / (1 + x);

	int ans = cnt * 2;
	if (cnt * (1 + x) == y) {

	} else if (cnt * (1 + x) + 1 == y) {
		ans++;
	} else {
		ans += 2;
	}

	std::cout << ans << '\n';
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