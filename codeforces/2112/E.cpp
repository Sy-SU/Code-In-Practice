#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int m;
	std::cin >> m;

	if (m % 2 == 0) {
		std::cout << -1 << '\n';
		return;
	}

	m--;
	int ans = 1;
	std::map<int, int> cost;

	int base = 1, ind = 0;
	while (1) {
		if (base >= 1000000) {
			break;
		}
		base *= 3;
		cost[base - 1] = ++ind;
	}
	// 2 1
	// 8 2
	// 26 3
	// 80 4
	// 242 5
	// 728 6
	// 2186 7
	// 6560 8
	// 19682 9
	// 59048 10
	// 177146 11
	int b[] = {177146, 59048, 19682, 6560, 2186, 728, 242, 80, 26, 8, 2};

	for (int i = 0; i < 11; i++) {
		if (m < b[i]) {
			continue;
		}
		int maxdel = m / b[i];
		m -= maxdel * b[i];
		// std::cerr << maxdel << " " << cost[b[i]] << '\n';
		ans += maxdel * cost[b[i]];
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