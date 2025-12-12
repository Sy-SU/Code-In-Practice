#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::map<i64, int> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	i64 ans = 0;
	int edge = 0;
	for (auto &[val, c] : cnt) {
		i64 del = c / 2;
		ans += val * del * 2;
		edge += del * 2;

		c %= 2;
	}

	// 小于 ans 的最大的剩余的
	std::vector<i64> res;
	for (auto [val, c] : cnt) {
		if (c > 0) {
			res.push_back(val);
		}
	}
	res.push_back(0), res.push_back(0);

	std::sort(res.begin(), res.end(), std::greater<i64>());

	if (edge == 0) {
		std::cout << 0 << '\n';
		return;
	}

	i64 maxans = 0;

	int sz = res.size();
	for (int i = 0; i + 1 < sz; i++) {
		if (res[i] - res[i + 1] >= ans) {
			continue;
		}
		if (res[i] == res[i + 1] && res[i] == 0 && edge == 2) {
			continue;
		}
		maxans = std::max(maxans, ans + res[i] + res[i + 1]);
	}

	std::cout << maxans << '\n';
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