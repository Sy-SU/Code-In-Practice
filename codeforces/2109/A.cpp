#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int cnt0 = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			cnt0++;
		}
		if (i > 1 && a[i] == a[i - 1] && a[i] == 0) {
			std::cout << "YES" << '\n';
			return;
		}
	}
	if (cnt0 == 0) {
		std::cout << "YES" << '\n';
		return;
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