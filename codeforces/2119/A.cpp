#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int a, b, x, y;
	std::cin >> a >> b >> x >> y;

	if (a > b) {
		if (a - b >= 2) {
			std::cout <<  -1 << '\n';
			return;
		}

		if (a % 2 == 0) {
			std::cout << -1 << '\n';
			return;
		}

		std::cout << y << '\n';

		return;
	}

	if (a == b) {
		std::cout << 0 << "\n";
		return;
	}

	int ans = 0;
	while (a != b) {
		// std::cerr << a << " " << b << '\n';
		if ((a ^ 1) == (a + 1)) {
			ans += std::min(x, y);
		} else {
			ans += x;
		}
		a++;
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