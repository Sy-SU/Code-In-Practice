#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	str = " " + str;
	if (str[1] == 's') {
		str[1] = '.';
	}
	if (str[n] == 'p') {
		str[n] = '.';
	}
	int cnts = 0, cntp = 0;
	for (int i = 1; i <= n; i++) {
		if (str[i] == 's') {
			cnts = 1;
		}
		if (str[i] == 'p') {
			cntp = 1;
		}
	}

	if (cnts + cntp == 2) {
		std::cout << "NO" << '\n';
	} else {
		std::cout << "YES" << '\n';
	}
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