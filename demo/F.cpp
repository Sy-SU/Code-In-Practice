#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m, x;
	std::cin >> n >> m >> x;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		if (m < a[i]) {
			ans += std::min(n - i + 1, x) * (a[i] - std::max(m * 1ll, a[i - 1]));
		}		
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}