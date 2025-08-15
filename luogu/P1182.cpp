#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int lo = 1, hi = 1e9;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&]() -> bool {
			i64 sum = 0, cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (sum + a[i] > mid) {
					cnt++;
					sum = 0;
					if (a[i] > mid) {
						return 0;
					}
				}
				sum += a[i];
			}
			return (cnt + 1) <= m;
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