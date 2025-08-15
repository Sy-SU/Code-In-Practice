#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 a, b, k;
	std::cin >> a >> b >> k;

	i64 g = std::__gcd(a, b);
	a /= g, b /= g;

	if (a <= k && b <= k) {
		std::cout << 1 << '\n';
	} else {
		std::cout << 2 << '\n';
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