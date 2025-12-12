#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int max = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (max > a[i]) {
			cnt++;
		}
		max = std::max(max, a[i]);
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