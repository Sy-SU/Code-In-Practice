#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 c, k;
	std::cin >> n >> c >> k;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	for (int r = 1; r <= 100; r++) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == -1 || a[i] > c) {
				continue;
			}
			i64 add = std::min(k, c - a[i]);
			k -= add, a[i] += add;

			c += a[i];
			a[i] = -1;
		}
	}

	std::cout << c << '\n';
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