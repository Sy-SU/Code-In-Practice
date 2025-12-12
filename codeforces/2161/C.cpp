#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 x;
	std::cin >> n >> x;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}

	// sum / x
	int incr = sum / x;
	std::sort(a.begin() + 1, a.end(), std::greater<i64>());

	std::vector<i64> b(n + 1);
	int l = 1, r = n;
	i64 now = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		// std::cerr << l << " " << r << '\n';
		if (l <= incr && (now + a[l]) / x > now / x) {
			// std::cerr << "l" << "\n";
			b[i] = a[l];
			ans += a[l], now += a[l];
			l++;
		} else {
			// std::cerr << "r" << '\n';
			b[i] = a[r];
			now += a[r];
			r--;
		}
	}

	std::cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		std::cout << b[i] << " \n"[i == n];
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