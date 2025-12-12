#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, x, y;
	std::cin >> n >> x >> y;

	std::string s;
	std::cin >> s;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += s[i] == '8';
	}

	x = std::abs(x), y = std::abs(y);
	if (x > n || y > n) {
		std::cout << "NO" << '\n';
		return;
	}

	if (x + y <= n + cnt) {
		std::cout << "YES" << '\n';
	} else {
		std::cout << "NO" << '\n';
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