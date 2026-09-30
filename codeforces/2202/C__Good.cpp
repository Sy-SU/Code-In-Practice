#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 sum = 0;
	auto calc = [&](int x, int y) -> i64 {
		i64 ans = 0;
		i64 l = -1, r = -1;
		for (int i = x; i <= y; i++) {
			if (a[i] >= l + 1 && a[i] <= r + 1) {
				r = a[i];
			} else {
				ans++;
				l = r = a[i];
			}
		}
		return ans;
	};

	for (int x = 1; x <= n; x++) {
		for (int y = x; y <= n; y++) {
			std::cerr << x << " " << y << " " << calc(x, y) << '\n';
			sum += calc(x, y);
		}
	}
	std::cout << sum << '\n';
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