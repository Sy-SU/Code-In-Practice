#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += (a[i] % 2 == 0);
	}
	if (cnt == 0) {
		std::cout << std::max(0, n - cnt - 1) << '\n';
	} else {
		std::cout << n - cnt + 1 << '\n';
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