#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	c -= a, d -= b;

	if (a > b) {
		std::swap(a, b);
	}

	if (c > d) {
		std::swap(c, d);
	}

	int maxb = (a + 1) * 2, maxd = (c + 1) * 2;
	if (maxb < b || maxd < d) {
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