#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, c;
	std::cin >> n >> c;

	std::vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	std::map<int, int> cnt;
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += cnt[a[i]];
		cnt[a[i] + c]++;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}