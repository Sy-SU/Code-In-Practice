#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = n - 1; i >= 1; i--) {
		if (a[i + 1] > 0) {
			a[i] += a[i + 1];
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += a[i] > 0;
	}
	std::cout << cnt << '\n';
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