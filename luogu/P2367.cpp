#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, p;
	std::cin >> n >> p;

	std::vector<int> a(n + 1, 0), del(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		del[i] = a[i] - a[i - 1];
	}

	while (p--) {
		int x, y, z;
		std::cin >> x >> y >> z;
		del[x] += z, del[y + 1] -= z;
	}

	int ans = 1e9, tmp = 0;
	for (int i = 1; i <= n; i++) {
		tmp += del[i];
		ans = std::min(ans, tmp);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}