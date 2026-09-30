#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] <= n) {
			vis[a[i]]++;
		}
	}

	i64 mex = -1;
	for (int i = 0; i <= n; i++) {
		if (vis[i] == 0) {
			mex = i;
			break;
		}
	}

	i64 maxe = *std::max_element(a.begin() + 1, a.end());
	std::map<i64, i64> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	std::vector<i64> b;

	b.push_back(maxe);
	cnt[maxe]--;

	for (int i = 0; i < mex; i++) {
		if (cnt[i] > 0) {
			b.push_back(i);
			cnt[i]--;
		}
	}

	for (auto [v, c] : cnt) {
		for (int i = 1; i <= c; i++) {
			b.push_back(v);
		}
	}

	i64 ans = b[0] * n, pmex = -1;
	std::vector<int> vi(n + 1);
	for (int i = 0; i < n; i++) {
		if (b[i] <= n) {
			vi[b[i]] = 1;
		}

		while (pmex + 1 <= n && vi[pmex + 1]) {
			pmex++;
		}

		ans += pmex + 1;
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