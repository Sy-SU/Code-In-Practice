#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> x(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> x[i].first >> x[i].second;
	}

	int ans = 0;
	for (int i = 1; i <= 1000; i++) {
		int cnt = 0;

		for (int j = 1; j <= n; j++) {
			if (i >= x[j].first && i <= x[j].second) {
				cnt++;
			}
		}

		ans = std::max(ans, cnt);
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}