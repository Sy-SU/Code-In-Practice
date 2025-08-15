#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, x, y;
	std::cin >> n >> x >> y;

	auto calc = [&](i64 i, i64 j) -> i64 {
		// std::cerr << i << " " << j << " " << (i - j + 1) * (j + x) + (n - i) * (2 * x + 2 * j - n + i - 1) / 2 << '\n';
		return (i - j + 1) * (x + j) + (n - i) * (2 * x + 2 * j - n + i - 1) / 2;
	};

	i64 ans = 0;
	for (i64 i = 1; i <= std::min(n, y); i++) {
		if (1 <= (n + 1 - x) / 2 && (n + 1 - x) / 2 <= i) {
			ans = std::max(ans, calc(i, (n + 1 - x) / 2));
		}
		ans = std::max({ans, calc(i, 1), calc(i, i)});
		i64 lst = std::max(0ll, x + 2 * i - n);
		ans = std::max(ans, (x + i + lst) * (x + i - lst + 1) / 2);
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