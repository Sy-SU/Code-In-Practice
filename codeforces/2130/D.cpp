#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (p[i] > p[j]) {
				ans++;
			}
		}
	}

	std::vector<int> bonus(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == i) {
				continue;
			}
			bonus[i] += (j < i ? 1 : -1) * (p[i] <= p[j] && p[j] <= 2 * n - p[i]);
		}
	}

	for (int ep = 1; ep <= n; ep++) {
		int maxbonus = 0;
		int bestp = -1;
		for (int i = 1; i <= n; i++) {
			if (p[i] >= n) {
				continue;
			}
			if (maxbonus < bonus[i]) {
				maxbonus = bonus[i];
				bestp = i;
			}
		}
		if (bestp == -1) {
			break;
		}

		p[bestp] = 2 * n - p[bestp];
		ans -= maxbonus;
	}
	std::cout << ans << '\n';
	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << p[i] << " \n"[i == n];
	// }
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