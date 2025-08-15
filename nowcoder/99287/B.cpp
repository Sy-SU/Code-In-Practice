#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	std::cin >> str;

	int n = str.length();
	if (str.length() == 1) {
		std::cout << ((str[0] - '0') % 4 ? "NO" : "YES") << '\n'; 
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			int num = (str[i] - '0') * 10 + str[j] - '0';
			// std::cerr << num << '\n';
			if (num % 4 == 0) {
				std::cout << "YES" << '\n';
				return;
			}
		}
	}
	std::cout << "NO" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}