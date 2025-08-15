#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;

	if ((a + b + c) % 3) {
		std::cout << "NO" << '\n';
		return;
	}

	int x = (a + b + c) / 3;
	if (a > x || b > x) {
		std::cout << "NO" << '\n';
		return;
	}

	std::cout << "YES" << '\n';
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