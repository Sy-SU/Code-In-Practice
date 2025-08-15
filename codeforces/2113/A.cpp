#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int k, a, b, x, y;
	std::cin >> k >> a >> b >> x >> y;

	if (x > y) {
		std::swap(x, y), std::swap(a, b);
	}

	int cnt = 0;

	int ok1 = (k >= a ? ((k - a) / x + 1) : 0);
	k -= ok1 * x;

	// assert(k + x >= a);

	int ok2 = (k >= b ? ((k - b) / y + 1) : 0);
	k -= ok2 * y;
	// assert(k + y >= b);

	std::cout << ok1 + ok2 << '\n';
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