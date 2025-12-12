#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 2);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> o;
	for (int i = 0; i < n; i++) {
		int l = (i + n - 1) % n, r = (i + 1) % n;
		o.push_back(std::min(std::max(a[i], a[l]), std::max(a[i], a[r])));
	}

	std::sort(o.begin(), o.end());

	i64 cost = 0;
	for (int i = 1; i < n; i++) {
		cost += o[i];
	}

	std::cout << cost << '\n';
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