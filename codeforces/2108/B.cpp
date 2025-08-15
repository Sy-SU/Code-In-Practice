#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, x;
	std::cin >> n >> x;

	if (n == 1 && x == 0) {
		std::cout << -1 << '\n';
		return;
	}

	if (x == 0) {
		if (n % 2 == 0) {
			std::cout << n << '\n';
		} else {
			std::cout << n + 3 << '\n';
		}
		return;
	}

	if (x == 1) {
		if (n % 2 == 1) {
			std::cout << n << '\n';
		} else {
			std::cout << n + 3 << '\n';
		}
		return;
	}

	int cnt = 0, _x = x;
	while (_x) {
		cnt += _x % 2;
		_x /= 2;
	}

	if (cnt >= n) {
		std::cout << x << '\n';
	} else {
		if (n % 2 == cnt % 2) {
			std::cout << x + n - cnt << '\n';
		} else {
			if (cnt >= 2 || x % 2 == 0) {
				std::cout << x + n - cnt + 1 << '\n';
			}
			
		}
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