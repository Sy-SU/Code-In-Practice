#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, x;
	std::cin >> n >> x;

	std::string str;
	std::cin >> str;

	str = " " + str;

	int l = 0, r = n + 1;
	for (int i = 1; i < x; i++) {
		if (str[i] == '#') {
			l = i;
		}
	}
	for (int i = n; i > x; i--) {
		if (str[i] == '#') {
			r = i;
		}
	}

	std::cout << std::max(std::min(x - 1 + 1, n + 1 - r + 1), std::min(l + 1, n + 1 - (x + 1) + 1)) << '\n';

	// std::min(l + 1, n + 1 - r + 1)
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