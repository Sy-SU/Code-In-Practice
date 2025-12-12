#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	int lo = 0, hi = 1e9, ans = 1e9;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int k) -> bool {
			int ptr = 0;
			for (int i = 1; i <= n; i++) {
				while (ptr < n && a[i] - a[ptr + 1] > k) {
					ptr++;
				}

				if (ptr != 1 && a[ptr] - a[1] > k) {
					return 0;
				}
			}
			return 1;
		};

		if (check(mid)) {
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

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}