#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	i64 k, c;
	std::cin >> n >> k >> c;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	std::vector<i64> b(n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] - i * c;
		ans += (i <= k ? a[i] : 0);
	}

	std::sort(b.begin() + 1, b.begin() + k + 1);
	std::sort(b.begin() + k + 1, b.begin() + n + 1);
	int l = 1, r = n;
	while (l <= k && r >= k + 1) {
		i64 bonus = b[r] - b[l];
		ans += std::max(0ll, bonus);

		l++, r--;
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}