#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, p;
	std::cin >> n >> p;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = (pre[i - 1] + a[i]) % p;
	}

	std::map<i64, int> map;
	map[0] = 0;
	i64 ans = -1;
	int ansl = -1, ansr = -1;
	for (int i = 1; i <= n; i++) {
		auto it = map.upper_bound(pre[i]);
		if (it == map.end()) {
			it = map.begin();
		}

		auto [v, ind] = *it;
		// std::cerr << ind + 1 << " " << i << " " << (pre[i] - v + p) % p << '\n';
		if ((pre[i] - v + p) % p > ans) {
			ans = (pre[i] - v + p) % p;
			ansl = ind + 1, ansr = i;
		}

		map[pre[i]] = i;
	}
	std::cout << ansl - 1 << " " << ansr - 1 << " " << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}