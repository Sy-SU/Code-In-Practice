#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 x;
	char op;
	std::cin >> x >> op;

	if (op == '*') {
		std::cout << x << " " << 1 << '\n';
	} else if (op == '+') {
		std::cout << x - 1 << " " << 1 << '\n';
	} else {
		std::cout << x + 1 << " " << 1 << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}