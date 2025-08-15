#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int w, h, a, b;
	std::cin >> w >> h >> a >> b;

	int x1, x2, y1, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	int dx = std::abs(x1 - x2), dy = std::abs(y1 - y2);

	bool isok = 0;

	if (dx && dx % a == 0) {
		isok = 1;
	}
	if (dy && dy % b == 0) {
		isok = 1;
	}

	std::cout << (isok ? "Yes" : "No") << '\n';
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