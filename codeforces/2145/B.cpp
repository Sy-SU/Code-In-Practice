#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string str;
	std::cin >> str;

	int l = -1, r = n;
	int cnt = 0;
	for (auto ch : str) {
		if (ch == '0') {
			l++;
		} else if (ch == '1') {
			r--;
		} else {
			cnt++;
		}
	}

	if (n == k) {
		for (int i = 0; i < n; i++) {
			std::cout << '-';
		}
		std::cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (i <= l || i >= r) {
			std::cout << '-';
		} else if (i <= l + cnt || i >= r - cnt) {
			std::cout << '?';
		} else {
			std::cout << '+';
		}
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