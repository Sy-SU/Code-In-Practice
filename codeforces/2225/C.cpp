#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<char>> map(2, std::vector<char>(n + 2));
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> map[i][j];
		}
	}

	int now = 1, ans = 0;
	while (now <= n) {
		if (map[0][now] == map[1][now]) {
			now++;
			continue;
		}
		if (now == n) {
			ans++, now++;
			continue;
		}
		if (map[0][now] == map[0][now + 1]) {
			ans += map[1][now] != map[1][now + 1];
			now += 2;
		} else if (map[1][now] == map[1][now + 1]) {
			ans += map[0][now] != map[0][now + 1];
			now += 2;
		} else {
			ans += 1;
			now += 1;
		}
	}
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