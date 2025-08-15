#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

#define int long long

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::vector<i64> p(n + 1), d(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> d[i];
	}

	std::map<i64, int> p2d;
	std::map<i64, bool> bl;

	for (int i = 1; i <= n; i++) {
		p2d[p[i]] = d[i];
		bl[p[i]] = 1;
	}


	int q;
	std::cin >> q;

	while (q--) {
		int now;
		std::cin >> now;

		int dir = 1;

		bool isok = 0;
		for (int t = 0; t <= 100000; t++) {
			// std::cerr << now << '\n';
			if (bl[now]) {
				dir = (t % k == p2d[now] ? -1 : 1) * dir;
			}

			now += dir;		
			if (now == 0 || now >= p[n] + 1) {
				std::cout << "YES" << '\n';
				isok = 1;
				break;
			}
		}
		if (isok == 0) {
			std::cout << "NO" << '\n';
		}
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}