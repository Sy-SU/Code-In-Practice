#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, a, b;
	std::cin >> n >> a >> b;

	if (b >= 3 * a) {
		std::cout << n * a << '\n';
		return;
	}

	i64 del = n / 3, res = n % 3;

	i64 ans = del * b;
	if (b >= res * a) {
		ans += res * a;
	} else {
		ans += b;
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