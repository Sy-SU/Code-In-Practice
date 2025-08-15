#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 g = 0;
	std::sort(a.begin() + 1, a.end());
	for (int i = 2; i <= n; i++) {
		if (a[i] % a[1] == 0) {
			g = std::__gcd(g, a[i]);
		}
	}
	std::cout << (g == a[1] ? "Yes" : "No") << '\n';
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