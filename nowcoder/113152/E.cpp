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

	std::map<i64, int> cnt;
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	i64 ans = 0;
	for (auto [num, ct] : cnt) {
		ans = std::max(ans, num * ct * num);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}