#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, x, y;
	std::cin >> n >> x >> y;

	i64 g = std::__gcd(x, y);
	i64 yg = y / g;

	std::cout << (n + yg - 1) / yg << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}