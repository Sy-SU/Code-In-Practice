#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	a[n + 1] = 0;

	bool isok = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[1]) {
			isok = 0;
		}
	}
	if (isok) {
		std::cout << 0 << '\n';
		return;
	}

	i64 ans = 1e18;
	int l = 1;
	for (int i = 2; i <= n + 1; i++) {
		if (a[i] != a[i - 1]) {
			i64 left = a[l] * (l - 1), right = a[i - 1] * (n - i + 1);
			ans = std::min(ans, left + right);
			l = i;
		}
	}
	std::cout << ans << '\n';
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