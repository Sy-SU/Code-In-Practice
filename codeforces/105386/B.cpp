#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 m;
	std::cin >> m;

	std::vector<i64> need;
	for (int i = 1; i <= n; i++) {
		need.push_back(k - a[i] % k);
	}
	std::sort(need.begin(), need.end());

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i] / k;
	}
	for (int i = 0; i < n; i++) {
		if (m >= need[i]) {
			m -= need[i];
			ans++;
		}
	}
	ans += m / k;
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