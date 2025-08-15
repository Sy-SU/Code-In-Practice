#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	for (int i = 0; i < 3; i++) {
		std::cin >> str[i];
	}

	if (str[0] == str[1] || str[1] == str[2] || str[0] == str[2]) {
		std::cout << "YES" << '\n';
	} else {
		std::cout << "NO" << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}