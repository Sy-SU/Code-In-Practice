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

	int ans = 1e9;

	for (int lst = 0; lst < 4; lst++) {
		// 正向 (lst - a[i] + 4) % 4
		// 反向 (a[i] - lst + 4) % 4

		int tmp = 0;
		for (int i = 1; i <= n; i++) {
			tmp += (a[i] - lst + 4) % 4;
		}

		tmp += (8 - tmp % 4 - lst) % 4;

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