#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 cnt = 0;
	for (int i = 3; i <= n; i++) {
		// 枚举 a 选的最大的那一个
		int maxbob = std::max(a[i], (i == n ? a[n - 1] : a[n]) - a[i]);
		for (int j = 2; j < i; j++) {
			// x + a[j] > maxbob
			int need = maxbob - a[j];

			int lo = 1, hi = j - 1;
			int lst = j;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;

				if (a[mid] > maxbob - a[j]) {
					hi = mid - 1;
					lst = mid;
				} else {
					lo = mid + 1;
				}
			}
			cnt += 1ll * (j - lst);
		}
	}
	std::cout << cnt << '\n';
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