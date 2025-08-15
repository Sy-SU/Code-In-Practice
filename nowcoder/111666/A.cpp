#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int x, y;
	std::cin >> x >> y;

	if (x == y) {
		std::cout << "Draw" << '\n';
	} else {
		if (x == 0) {
			if (y == 2) {
				std::cout << "chengwins" << '\n';
			} else {
				std::cout << "Hongwins" << '\n';
			}
		} else if (x == 2) {
			if (y == 0) {
				std::cout << "Hongwins" << '\n';
			} else {
				std::cout << "chengwins" << '\n';
			}
		} else {
			if (y == 0) {
				std::cout << "chengwins" << '\n';
			} else {
				std::cout << "Hongwins" << '\n';
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}