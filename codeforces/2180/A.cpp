#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int l, a, b;
	std::cin >> l >> a >> b;

	int g = std::gcd(b, l);

	int ans = 0, now = a;
	for (int i = 0; i < l * 2; i++) {
		ans = std::max(ans, now);
		now = (now + b) % l;
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