#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	int sit = (1 << (n - 1));
	for (int s = 0; s < sit; s++) {
		std::vector<std::pair<int, int>> checklist;
		int l = 1, r = -1;

		int nows = s;
		for (int i = 1; i < n; i++) {
			if (nows % 2) {
				r = i;
				checklist.push_back({l, r});

				l = r + 1;
			}
			nows /= 2;
		}

		checklist.push_back({l, n});

		bool isok = 1;

		std::vector<int> med;
		for (auto [l, r] : checklist) {
			std::vector<int> v;
			for (int i = l; i <= r; i++) {
				v.push_back(a[i]);
			}
			int sz = v.size();
			if (sz % 2 == 0) {
				isok = 0;
			}
			std::sort(v.begin(), v.end()); 
			med.push_back(v[sz / 2]);
		}
		for (auto md : med) {
			if (md != med[0]) {
				isok = 0;
			}
		}
		if (isok) {
			ans = std::max(ans, (int)checklist.size());
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