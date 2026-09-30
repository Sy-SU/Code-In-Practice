#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1);
	std::vector<int> b(m + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}
	b[m + 1] = 0;

	std::vector<i64> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	std::sort(b.begin() + 1, b.end(), std::greater<int>());
	b[0] = n;

	i64 ans = 0;
	for (int i = 1; i <= m + 1; i++) {
		i64 add = pre[b[i - 1]] - pre[b[i]];
		if (i != 1) {
			ans += std::abs(add);
		} else {
			ans += add;
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