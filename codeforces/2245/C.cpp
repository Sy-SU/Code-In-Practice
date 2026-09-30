#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	int bet = 1;
	while (bet < n) {
		bet *= 2;
	}

	i64 l = -1, r = -1;
	if (bet == n) {
		l = n, r = 2 * n - 1;
	} else {
		l = 0, r = bet - 1;
	}

	if (k < l || k > r) {
		std::cout << "NO" << '\n';
		return;
	}

	std::cout << "YES" << '\n';

	std::vector<int> p(n + 1);
	if (k == 0) {
		int x = -1, y = -1;
		for (int a = 1; a < n; a++) {
			int b = a ^ n;
			if (a < n && b < n && a != b) {
				x = std::min(a, b), y = std::max(a, b);
				break;
			}
		}

		assert(x != -1 && y != -1);

		p[n - 1] = x, p[n] = y, p[n - 2] = 0;

		int now = 0;
		for (int i = 1; i < n - 2; i++) {
			while (now == p[n] || now == p[n - 1] || now == p[n - 2]) {
				now++;
			}
			p[i] = now;
			now++;
		}
	} else if (n == k) {
		p[n] = 0;
		for (int i = 1; i < n; i++) {
			p[i] = i;
		}
	} else {
		
		if ((n ^ k) < n) {
			p[n] = n ^ k, p[n - 1] = 0;

			int now = 0;
			for (int i = 1; i < n - 1; i++) {
				while (now == p[n] || now == p[n - 1]) {
					now++;
				}
				p[i] = now;
				now++;
			}
		} else {
			int h = bet / 2, g = (n ^ k) ^ h;
			if (h > g) {
				std::swap(h, g);
			}

			p[n] = g, p[n - 1] = h, p[n - 2] = 0;
			int now = 0;
			for (int i = 1; i < n - 2; i++) {
				while (now == p[n] || now == p[n - 1] || now == p[n - 2]) {
					now++;
				}
				p[i] = now;
				now++;
			}
		}
		
	}
	

	for (int i = 1; i <= n; i++) {
		std::cout << p[i] << " \n"[i == n];
	}

	// int xr = 0;
	// for (int i = 1; i <= n; i++) {
	// 	std::map<int, int> vis;
	// 	for (int j = 1; j <= i; j++) {
	// 		vis[p[j]] = 1;
	// 	}

	// 	int mex = 0;
	// 	for (int k = 0; k <= n; k++) {
	// 		if (vis[k] == 0) {
	// 			mex = k;
	// 			break;
	// 		}
	// 	}
	// 	xr ^= mex;
	// 	// std::cerr << mex << " \n"[i == n];
	// }
	// // std::cerr << "xr = " << xr << " k = " << k << '\n';std::cerr << '\n';
	// assert(xr == k);
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