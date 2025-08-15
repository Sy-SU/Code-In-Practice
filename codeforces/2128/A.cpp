#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, c;
	std::cin >> n>> c;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::map<int, int> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	std::vector<int> b;
	while (c) {
		b.push_back(c);
		c /= 2;
	}
// 10 5 2 1 
	std::sort(b.begin(), b.end());

	int ans = n;
	for (auto coin : b) {
		int max = -1;
		for (auto [cost, num] : cnt) {
			if (cost <= coin && num > 0) {
				max = std::max(max, cost);
			}
		}
		if (max != -1) {
			ans--;
			cnt[max]--;		
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