#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	std::cin >> str;

	if (str == "U" || str == "D") {
		std::cout << "L" << '\n';
	} else {
		std::cout << "U" << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}