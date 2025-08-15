#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	int min = 1e9;
	for (int i = 1; i <= n; i++) {
		if (b[i] >= min * 2) {
			std::cout << "NO" << "\n";
			return;
		}
		min = std::min(min, b[i]);
	}

	std::cout << "YES" << '\n';
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