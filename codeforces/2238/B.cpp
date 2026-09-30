#include <bits/stdc++.h>

using i64 = long long;

i64 lcm(i64 x, i64 y) {
	return x * y / std::gcd(x, y);
}

void solve() {
	i64 n;
	std::cin >> n;

	i64 ans = 0;
	for (int b = 1; b <= n; b++) {
		ans += (n / b) * 1ll * (n / b);
	}
	std::cout << ans << '\n';
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