#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end(), std::greater<i64>());

	std::vector<i64> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	while (q--) {
		i64 x;
		std::cin >> x;

		int lo = 1, hi = n, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (pre[mid] >= x) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		std::cout << ans << '\n';
	}

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}