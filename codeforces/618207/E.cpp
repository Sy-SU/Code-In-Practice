#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, a, b;
	std::cin >> n >> a >> b;

	auto f = [&](i64 x) -> i64 {
		return n + (a + n * b - 1) * x - b * x * x;
	};

	i64 ans = std::max(f(0), f(n));

	if (b) {
		i64 best = (a + n * b - 1) / (2 * b);
		if (best >= 0 && best <= n) {
			for (i64 t = best - 1; t <= best + 1; t++) {
				if (t >= 0 && t <= n) {
					ans = std::max(ans, f(t));
				}
			}
		}
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