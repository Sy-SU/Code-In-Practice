#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::vector<int> a(7);
	for (int i = 0; i < 7; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < 7; i++) {
		if (a[i] == 4 || a[i] == 7) {
			std::cout << "NO" << '\n';
			return;
		}
	}
	std::cout << "YES" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}