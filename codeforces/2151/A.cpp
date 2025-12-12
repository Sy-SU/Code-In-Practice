#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}
	
	for (int i = 2; i <= m; i++) {
		if (a[i] != a[i - 1] + 1) {
			std::cout << 1 << '\n';
			return;
		}
	}

	std::cout << n - a[m] + 1 << '\n';
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