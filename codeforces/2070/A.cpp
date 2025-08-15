#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n;
	std::cin >> n;

	n++;

	i64 ans = (n - 1) / 15 * 3 + std::min(3ll, n % 15);
	if (n % 15 == 0) {
		ans += 3;
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