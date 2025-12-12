#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	s = " " + s + " ";

	std::vector<int> pre(n + 2);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + (s[i] == 'a' ? 1 : -1);
	}

	std::vector<int> suf(n + 2);
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + (s[i] == 'a' ? 1 : -1);
	}

	std::map<int, std::vector<int>> val;
	for (int i = 1; i <= n; i++) {
		val[suf[i]].push_back(i);
	}
	val[0].push_back(n + 1);

	int min = 1e9;
	for (int l = 0; l <= n; l++) {
		// 1 ~ l, r ~ n
		// l < r
		int need = -pre[l];

		int sz = val[need].size();
		int lo = 0, hi = sz - 1, ans = -100;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (val[need][mid] > l) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		if (ans == -100) {
			continue;
		}

		int r = val[need][ans];
		if (l == 0 && r == n + 1) {
			continue;
		}

		min = std::min(min, r - l - 1);
	}

	if (min == 1e9) {
		std::cout << -1 << '\n';
		return;
	}
	std::cout << min << '\n';
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