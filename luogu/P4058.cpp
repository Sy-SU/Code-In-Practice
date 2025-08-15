#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	ui64 s, l;
	std::cin >> n >> s >> l;

	std::vector<int> h(n + 1), a(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 lo = 0, hi = 1e18;
	ui64 ans = 0;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&h, &a, mid, n, l, s] () -> bool {
			i64 sum = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] >= 1e18 / mid) {
					sum += 1e18;
				}
				sum += h[i] + a[i] * mid >= l ? h[i] + a[i] * mid : 0;
				if (sum >= 1e18) {
					sum = 1e18;
				}
			}

			return sum >= s;
		};

		if (check()) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
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