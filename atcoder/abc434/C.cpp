#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, h;
	std::cin >> n >> h;

	int lo = h, hi = h, now = 0;

	bool isok = 1;

	for (int i = 1; i <= n; i++) {
		int t, l, r;
		std::cin >> t >> l >> r;

		// now - t
		lo = std::max(l, lo - (t - now)), hi = std::min(r, hi + (t - now));

		if (lo > hi) {
			isok = 0;
		}

		now = t;
	}

	std::cout << (isok ? "Yes" : "No") << '\n';
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