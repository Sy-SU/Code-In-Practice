#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(m + 2, 0), suf(m + 2, 0);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.begin() + m + 1);

	for (int i = m; i >= 1; i--) {
		suf[i] = suf[i + 1] + a[i];
	}

	i64 ans = 0;
	for (int i = 1; i <= m; i++) {
		int lo = i + 1, hi = m;
		int lst = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			auto check = [&](int x) -> bool {
				if (a[i] + a[x] >= n) {
					return 1;
				} else {
					return 0;
				}
			};

			if (check(mid)) {
				hi = mid - 1;
				lst = mid;
			} else {
				lo = mid + 1;
			}
		}
		if (lst == -1) {
			continue;
		}


		ans += (a[i] - n + 1) * (m - lst + 1) + suf[lst];
	} 
	std::cout << ans * 2 << '\n';
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