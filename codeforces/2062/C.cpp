#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1, 0);
	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}

	i64 ans = sum;
	while (n != 1) {
		ans = std::max({ans, a[n] - a[1], a[1] - a[n]});
		for (int i = 1; i < n; i++) {
			a[i] = a[i + 1] - a[i];
		}
		n--;
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