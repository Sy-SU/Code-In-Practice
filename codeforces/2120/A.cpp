#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int a[3], b[3];
	for (int i = 0; i < 3; i++) {
		std::cin >> a[i] >> b[i];
	}

	if (a[0] > b[0]) {
		std::swap(a, b);
	}

	if (b[0] == b[1] + b[2] && a[1] == a[2] && a[0] + a[1] == b[0]) {
		std::cout << "YES" << '\n';
		return;
	}

	if (b[0] == b[1] && b[0] == b[2] && b[0] == a[0] + a[1] + a[2]) {
		std::cout << "YES" << '\n';
		return;
	}

	if (b[0] != b[1] + b[2]) {
		std::cout << "NO" << '\n';
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