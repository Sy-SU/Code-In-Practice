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

	int x = 0, y = 0;
	for (i64 k = 1; k <= kmax; k++) {
		i64 l = std::max(0ll, 2 * k - m), r = std::min(k, n - k);
		if (x < l) {
			x++, y--;
		} else if (x > r) {
			x--, y++;
		}

		int x1 = x + 1, y1 = y;
		int x2 = x, y2 = y + 1;

		i64 ans = -1;
		i64 ans1 = -1, ans2 = -1;
		if (x1 >= std::max(0ll, 2 * k - m) && x1 <= std::min(k, n - k)) {
			ans1 = prea[x1] + preb[y1];
		}
		if (x2 >= std::max(0ll, 2 * k - m) && x2 <= std::min(k, n - k)) {
			ans2 = prea[x2] + preb[y2];
		}
		assert(ans1 != -1 || ans2 != -1);
		if (ans1 >= ans2) {
			ans = ans1;
			x = x1, y = y1;
		} else {
			ans = ans2;
			x = x2, y = y2;
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