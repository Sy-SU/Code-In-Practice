#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	} 

	std::vector<int> one, tw;
	for (int i = 1; i <= n; i++) {
		if (a[i] % 2) {
			one.push_back(a[i]);
		} else {
			tw.push_back(a[i]);
		}
	}

	if (one.empty()) {
		std::cout << 0 << '\n';
	} else {
		i64 ans = 0;
		for (auto num : tw) {
			ans += num;
		}

		std::sort(one.begin(), one.end(), std::greater<int>());
		int x = one.size();
		for (int i = 0; i <= (x - 1) / 2; i++) {
			ans += one[i];
		}

		std::cout << ans << '\n';
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