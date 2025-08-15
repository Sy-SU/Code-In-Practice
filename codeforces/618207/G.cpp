#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	int cnt = 0, now = 1;
	i64 sum = 0;

	while (now <= n) {
		cnt++, sum += a[now];

		int lo = now + 1, hi = n;
		int nxt = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (a[mid] >= sum) {
				nxt = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		if (nxt == -1) {
			break;
		}

		now = nxt;
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