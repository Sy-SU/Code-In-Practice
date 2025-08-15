#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	int ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			if (a[l] % 2 == a[r] % 2) {
				ans = std::max(ans, r - l + 1);
			}
		}
	}
	std::cout << n - ans << '\n';
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