#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a, b, n;
	std::cin >> a >> b >> n;

	i64 ans = 2;
	
	if (b * n <= a) {
		ans = 1;
	}
	if (a == b) {
		ans = 1;
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