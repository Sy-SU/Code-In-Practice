#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] = std::abs(a[i] - k);
	}

	std::sort(a.begin() + 1, a.end());
	std::cout << a[m] << '\n';
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