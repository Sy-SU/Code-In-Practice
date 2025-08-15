#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int k;
	std::cin >> k;

	if (k == 0) {
		std::cout << '1' << '\n';
		return;
	}

	int cnt = k / 2, res = k % 2;
	std::string ans;

	if (res) {
		std::cout << 4;
		for (int i = 1; i <= cnt; i++) {
			std::cout << 8;
		}
		std::cout << '\n';
	} else {
		for (int i = 1; i <= cnt; i++) {
			std::cout << 8;
		}
		std::cout << '\n';
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