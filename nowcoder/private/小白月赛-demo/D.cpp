#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, s;
	std::cin >> n >> s;

	auto mysqrt = [&](i64 x) -> i64 {
		i64 lo = 1, hi = 1e9;
		i64 ans = -1;
		while (lo <= hi) {
			i64 mid = (lo + hi) / 2;
			if (mid * mid <= x) {
				hi = mid - 1;
				ans = mid;
			} else {
				lo = mid + 1;
			}
		}
		return ans;
	};

	i64 sq = mysqrt(n);

	if (s <= sq) {
		std::cout << s - 1 << '\n'; 
	} else {
		i64 ans = s - 1;
		for (int x = n / s; x <= n / s + 1; x++) {
			ans = std::min(ans, x + std::abs(n / x - s));
		}
		std::cout << ans << '\n';
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