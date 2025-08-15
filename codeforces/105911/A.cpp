#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::vector<int> a(4);
	for (int i = 0; i < 4; i++) {
		std::cin >> a[i];
	}

	std::cout << (a[0] + a[1] + a[2]) * a[3] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}