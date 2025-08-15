#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, s;
	std::cin >> n >> s;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int dx, dy, x, y;
		std::cin >> dx >> dy >> x >> y;

		bool isok = 0;
		if (x + y == s) {
			if (dx != dy) {
				isok = 1;
			}
		} 

		if (x == y) {
			if (dx == dy) {
				isok = 1;
			}
		}

		cnt += isok;
	}

	std::cout << cnt << '\n';
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