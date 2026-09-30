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

	int lo = 0, hi = 2e5, mex = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int m) -> bool {
			// 0 ~ m - 1 ok
			std::vector<int> need(m);

			for (int i = 0; i < m; i++) {
				need[i] = 1;
			}

			std::queue<int> q;
			for (int i = 1; i <= n; i++) {
				if (a[i] < m && need[a[i]]) {
					need[a[i]] = 0;
				} else {
					q.push(a[i]);
				}
			}

			for (int i = 0; i < m; i++) {
				if (need[i] == 0) {
					continue;
				}
				while (!q.empty() && q.front() <= 2 * i) {
					q.pop();
				}

				if (q.empty()) {
					break;
				}

				need[i] = 0;
				q.pop();
			}

			for (int i = 0; i < m; i++) {
				if (need[i]) {
					return 0;
				}
			}
			return 1;
		};

		if (check(mid)) {
			lo = mid + 1;
			mex = mid;
		} else {
			hi = mid - 1;
		}
	}
	std::cout << mex << '\n';
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