#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::cin.ignore();

	std::cout << n << " nya" << '\n';

	for (int i = 1; i <= n; i++) {
		std::string str;
		std::getline(std::cin, str);

		std::cout << str << " nya" << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}