#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> m >> n;

	std::vector<i64> a(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;

	std::vector<i64> now = a;
	while (n--) {
		std::sort(now.begin() + 1, now.end());

		i64 min = 1e9;
		int choose = -1;
		for (int i = 1; i < m; i++) {
			if (now[i + 1] - now[i] < min) {
				min = now[i + 1] - now[i];
				choose = i; // ch, ch + 1
			}
		}

		std::vector<i64> lst;
		lst.push_back(0);

		ans += min * min;

		for (int i = 1; i <= m; i++) {
			if (i == choose || i == choose + 1) {
				continue;
			}
			lst.push_back(now[i]);
		}

		now = lst;

		m -= 2;
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}