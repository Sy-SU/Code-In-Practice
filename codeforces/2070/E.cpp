#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;
	str = " " + str;
	// 00
	// 001
	// 0010010
	// 010
	// 0100100
	// 100
	// 00
	// 001
	// 010
	// 100
	// 00
	// 001

	// B 优先拿 10
	// 0 1 0 1 0 1 0 1
	// 5 7 8 9 1 2 3 4

	// 0 1 0 1
	// 1 5 4 1
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}