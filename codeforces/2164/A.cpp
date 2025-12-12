#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 x;
	std::cin >> x;

	i64 max = *std::max_element(a.begin() + 1, a.end()), min = *std::min_element(a.begin() + 1, a.end());
	if (max < x || min > x) {
		std::cout << "NO" << '\n';
	} else {
		std::cout << "YES" << '\n';
	}
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