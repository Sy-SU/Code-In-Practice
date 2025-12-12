#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;

		a[i] = {x, i};
	}

	std::sort(a.begin() + 1, a.end());

	std::vector<int> cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		cnt[a[i].first]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[a[i].first] == 1) {
			std::cout << a[i].second << '\n';
			return;
		}
	}
	
	std::cout << -1 << '\n';
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