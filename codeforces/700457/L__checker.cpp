#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	std::vector<int> premax(n + 2), sufmin(n + 2, 1e9);
	for (int i = 1; i <= n; i++) {
		
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