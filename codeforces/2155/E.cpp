#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	int ans = 0;
	std::map<std::pair<int, int>, int> cnt;
	for (int i = 1; i <= k; i++) {
		int x, y;
		std::cin >> x >> y;

		cnt[{x, y}]++;
	}

	for (auto [pos, c] : cnt) {
		c %= 2;
		if (c) {
			auto [x, y] = pos;
			std::cerr  << x << " " << y << '\n';
			if (y % 2 == 0) {
				continue;
			}
			ans ^= (x + y) % 2;
		}
	}

	std::cout << ((1 - ans) ? "Mimo" : "Yuyu") << "\n";
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