#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 x;
	std::cin >> x;

	int ans = 0;
	while (x) {
		if (x % 10 == 8) {
			ans += 2;
		} else if (x % 10 == 2 || x % 10 == 6 || x % 10 == 9 || x % 10 == 0) {
			ans++;
		}
		x /= 10;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}