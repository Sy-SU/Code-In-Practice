#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int w, b;
	std::cin >> w >> b;

	std::cout << (1000 * w + 1 + b - 1) / b << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}