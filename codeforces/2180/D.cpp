#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> d(n + 1);
	for (int i = 1; i < n; i++) {
		d[i] = a[i + 1] - a[i];
	}
	d[n] = 1e18;

	i64 l = 0, r = 1e18, ans = 0;
	for (int i = 1; i < n; i++) {
		bool isok = 0;
		if (d[i] > l) {
			ans++;
			isok = 1;
			i64 nl = std::max(0ll, d[i] - r), nr = std::max(0ll, d[i] - l);
			nl = std::min(nl, d[i + 1]);
			nr = std::min(nr, d[i + 1]);
			l = nl, r = nr;
		} else {
			i64 nl = 0, nr = std::max(0ll, d[i] - l);
			nl = std::min(nl, d[i + 1]);
			nr = std::min(nr, d[i + 1]);
			l = nl, r = nr;
		}
		// std::cerr << l << " " << r << "    " << isok << '\n';
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