#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	char x1 = s[0], x2 = s[1];
	int n1 = s[0] - '0', n2 = s[1] - '0';

	int n = n1 * 10 + n2;

	std::string ans;
	if (n == 1) {
		ans = "000000000000";
	} else if (n == 2) {
		ans = "000000000001";
	} else if (n == 3) {
		ans = "000000000021";
	} else if (n == 4) {
		ans = "000000000321";
	} else if (n == 5) {
		ans = "000000004321";
	} else if (n == 6) {
		ans = "000000054321";
	} else if (n == 7) {
		ans = "000000654321";
	} else if (n == 8) {
		ans = "760000054321";
	} else if (n == 11) {
		ans = "876000054321";
	} else if (n == 22) {
		ans = "876100054321";
	} else if (n == 33) {
		ans = "876120054321";
	} else {
		std::cout << "No" << '\n';
		return;
	}
	std::cout << "Yes" << '\n';
	for (auto ch : ans) {
		std::cout << ch << " ";
	}
	std::cout << '\n';
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