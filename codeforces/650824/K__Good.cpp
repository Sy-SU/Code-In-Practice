#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int k;
	std::cin >> k;

	for (int i = 1; i <= n; i++) {
		if (a[i] > k) {
			a[i] = 1;
		} else if (a[i] < k) {
			a[i] = -1;
		} else {
			a[i] = 0;
		}
	}

	std::map<int, std::vector<int>> ind;
	std::vector<int> pre0(n + 1), pre(n + 1);

	ind[0].push_back(0);
	for (int i = 1; i <= n; i++) {
		pre0[i] = pre0[i - 1] + (a[i] == 0);
		pre[i] = pre[i - 1] + a[i];
		ind[pre[i]].push_back(i);
	}

	i64 ans = 0;
	for (auto [v, vec] : ind) {
		int sz = vec.size();
		for (int r = 0; r < sz; r++) {
			int ok = -1;
			for (int l = 0; l <= r; l++) {
				if (pre0[vec[r]] - pre0[vec[l]] <= 0) {
					break;
				} 
				ok = l;
			}

			ans += ok + 1;
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