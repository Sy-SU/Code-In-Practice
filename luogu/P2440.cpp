#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n;
	std::cin >> n;
	
	i64 lo = 0, hi = 1e5;
	i64 ans = 0;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;
		
		if (mid * mid * mid <= n) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}
