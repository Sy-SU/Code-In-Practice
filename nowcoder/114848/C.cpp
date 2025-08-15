#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> cnt(200000 + 1);
	for (int i = 1; i <= 2 * n; i++) {
		cnt[a[i]]++;
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += std::min(2, cnt[i]);
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}