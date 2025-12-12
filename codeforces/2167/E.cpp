#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k, x;
	std::cin >> n >> k >> x;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	int lo = 1, hi = 1e9, ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&](int dis) -> bool {
			int cnt = 0;
			for (int i = 2; i <= n; i++) {
				cnt += std::max(0, (a[i] - dis) - (a[i - 1] + dis) + 1);	
			}

			cnt += std::max(0, a[1] - dis + 1) + std::max(0, x - a[n] - dis + 1);

			return cnt >= k;
		};

		if (check(mid)) {
			lo = mid + 1;
			ans = mid;
		} else {
			hi = mid - 1;
		}
	}

	// std::cout << ans << "\n";

	if (ans == 0) {
		for (int i = 0; i < k; i++) {
			std::cout << i << " \n"[i == k - 1];
		}
		return;
	}
	std::vector<int> pos;

	for (int i = 0; i <= a[1] - ans; i++) {
		pos.push_back(i);
		if (pos.size() >= k) {
			break;
		}
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = a[i - 1] + ans; j <= a[i] - ans; j++) {
			pos.push_back(j);
			if (pos.size() >= k) {
				break;
			}
		}
	}

	for (int i = a[n] + ans; i <= x; i++) {
		pos.push_back(i);
		if (pos.size() >= k) {
			break;
		}
	}

	for (int i = 0; i < k; i++) {
		std::cout << pos[i] << " \n"[i == k - 1];
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