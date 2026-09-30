#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::set<i64> join;

	std::map<i64, i64> ans;
	for (int i = 1; i <= n; i++) {
		std::map<i64, i64> cnt, vis;
		int idx = 0;
		while (1) {
			if (vis[a[i]] != 0) {
				break;
			}

			vis[a[i]] = 1;
			cnt[a[i]] = idx;
			idx++;

			if (a[i] % 2) {
				a[i]++;
			} else {
				a[i] /= 2;
			}
		}

		if (i >= 2) {
			std::set<i64> tmp;
			for (auto num : join) {
				if (vis[num] != 0) {
					tmp.insert(num);
					ans[num] += cnt[num];
				}
			}
			join = tmp;
		} else {
			for (auto [num, ct] : vis) {
				join.insert(num);
				ans[num] += cnt[num];
			}
		}
	

		// for (auto num : join) {
		// 	std::cerr << "join " << num << '\n';
		// }
	}


	i64 minans = 1e18;
	for (auto num : join) {
		minans = std::min(minans, ans[num]);
	}
	std::cout << minans << '\n';
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