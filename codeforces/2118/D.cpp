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

	for (int i = 1; i <= n; i++) {
		p2d[p[i]] = d[i];
	}

	int q;
	std::cin >> q;

	while (q--) {
		i64 now;
		std::cin >> now;

		i64 t = 0;
		int lst = -1;
		for (int i = 1; i <= n; i++) {
			if (now <= p[i]) {
				lst = i;
				break;
			}
		}
		// now -> lst
		if (lst == -1) {
			std::cout << "YES" << '\n';
			continue;
		}

		t = p[lst] - now;

		// now at p[lst]

		std::map<std::pair<i64, std::pair<i64, int>>, bool> vis;


		int dir = (t % k == p2d[p[lst]] ? -1 : 1);
		// vis[{lst, {t % k, dir}}] = 1;

		while (true) {
			int to = lst + dir;
			// lst -> to

			i64 needtime = std::abs(p[lst] - p[to]);
			if (to == n + 1 || to == 0) {
				std::cout << "YES" << '\n';
				break;
			}

			// std::cerr << "vis" << to << " " << (t + needtime) % k << " " << (t % k == p2d[p[lst]] ? -1 : 1) * dir << '\n';
			if (vis[{lst, {t % k, dir}}] == 1) {
				std::cout << "NO" << '\n';
				break;
			}

			vis[{lst, {t % k, dir}}] = 1;

			// std::cerr << lst << " " << to << " " << needtime <<  '\n';
			lst = to, t = (t + needtime) % k;
			dir = (t % k == p2d[p[lst]] ? -1 : 1) * dir;
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