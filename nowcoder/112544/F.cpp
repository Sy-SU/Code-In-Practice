#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, m;
	std::cin >> n >> m;

	i64 lo = n / m - 1, hi = n / m, ans = -1;
	for (int i = lo; i <= hi; i++) {
		auto check = [&](i64 r) -> bool {
			i64 x = n - m * r;
			if (x < 0) {
				return 0;
			}

			// 0 ~ m 个 2^? -> x
			std::vector<i64> ok;
			i64 base = 1;
			for (int i = 1; i <= 40; i++) {
				if ((base & r) == 0) {
					ok.push_back(base);
				}
				base <<= 1;
			}
			std::reverse(ok.begin(), ok.end());

			for (auto bs : ok) {
				i64 need = std::min(m, x / bs);
				// std::cerr << bs <<" " << need << '\n';
				x -= bs * need;
			}

			return (x == 0);
		};

		if (check(i)) {
			ans = i;
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