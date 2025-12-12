#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::map<int, int> cnt;
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;

		cnt[x]++;
	}

	for (auto [_, c] : cnt) {
		if (c >= 2) {
			std::cout << "YES" << '\n';
			return;
		}
	}

	std::cout << "NO" << '\n';
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