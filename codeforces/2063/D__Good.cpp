#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];	
	}

	std::sort(a.begin() + 1, a.end());
	std::sort(b.begin() + 1, b.end());

	i64 kmax = std::min({n, m, (n + m) / 3});
	std::cout << kmax << '\n';

	std::vector<i64> bonusa(n + 1), bonusb(m + 1);
	for (int i = 1; i <= n / 2; i++) {
		bonusa[i] = a[n + 1 - i] - a[i];
	}
	for (int i = 1; i <= m / 2; i++) {
		bonusb[i] =	b[m + 1 - i] - b[i];
	}

	std::vector<i64> prea(n + 1, 0), preb(m + 1, 0);
	for (int i = 1; i <= n / 2; i++) {
		prea[i] = prea[i - 1] + bonusa[i];
	}
	for (int i = 1; i <= m / 2; i++) {
		preb[i] = preb[i - 1] + bonusb[i];
	}

	for (i64 k = 1; k <= kmax; k++) {
		i64 ans = 0;
		for (i64 x = std::max(0ll, 2 * k - m); x <= std::min(k, n - k); x++) {
			i64 y = k - x;
			ans = std::max(ans, prea[x] + preb[y]);
		}
		std::cout << ans << " \n"[k == kmax];
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