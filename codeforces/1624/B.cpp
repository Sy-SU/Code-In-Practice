#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 a, b, c;
	std::cin >> a >> b >> c;

	if (a % 2 == c % 2 && ((a + c) / 2) % b == 0) {
		std::cout << "YES" << '\n';
		return;
	}
	if (2 * b > c && (2 * b - c) % a == 0) {
		std::cout << "YES" << '\n';
		return;
	}
	if (2 * b > a && (2 * b - a) % c == 0) {
		std::cout << "YES" << '\n';
		return;
	}
	std::cout << "NO" << '\n';
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