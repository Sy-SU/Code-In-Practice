#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

i64 n, k;

i64 work(int l, int r) {
	if (r - l + 1 < k) {
		return 0;
	}

	if (l % 2 != r % 2) {
		return work(l, (l + r) / 2) + work((l + r) / 2 + 1, r);
	} else {
		return (l + r) / 2 + work(l, (l + r) / 2 - 1) + work((l + r) / 2 + 1, r);
	}
}

void solve() {
	std::cin >> n >> k;

	i64 ans = 0;
	ans += work(1, n);
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