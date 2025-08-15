#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> d(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> d[i];
	}

	std::vector<int> l(n + 1), r(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i] >> r[i];
	}

	std::vector<int> lo(n + 1), hi(n + 1);
	for (int i = 1; i <= n; i++) {
		if (d[i] != -1) {
			lo[i] = lo[i - 1] + d[i], hi[i] = hi[i - 1] + d[i];
		} else {
			lo[i] = lo[i - 1], hi[i] = hi[i - 1] + 1;
		}

		if (lo[i] > r[i] || hi[i] < l[i]) {
			std::cout << -1 << '\n';
			return;
		}
		lo[i] = std::max(lo[i], l[i]), hi[i] = std::min(hi[i], r[i]);
	}

	int now = lo[n];
	for (int i = n; i >= 1; i--) {
		if (d[i] != -1) {
			now -= d[i];
		} else {
			if (now >= lo[i - 1] && now <= hi[i - 1]) {
				d[i] = 0;
			} else if ((now - 1 >= lo[i - 1]) && (now - 1 <= hi[i - 1])) {
				d[i] = 1;
			} else {
				assert(0);
			}
			now -= d[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << d[i] << " \n"[i == n];
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