#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int l, n, k;
	std::cin >> l >> n >> k;

	std::vector<int> a(n + 3, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	a[n + 1] = 0, a[n + 2] = l;
	n += 2;

	std::sort(a.begin() + 1, a.end());

	int lo = 1, hi = 1e9;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&]() -> bool {
			int cnt = 0;
			for (int i = 2; i <= n; i++) {
				cnt += (a[i] - a[i - 1] - 1) / mid;
			}
			return cnt <= k;
		};

		if (check()) {
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

	solve();

	return 0;
}