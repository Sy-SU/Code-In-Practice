#include <bits/stdc++.h>

using i64 = long long;

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

int rng(int l, int r) { // [l, r]
	return rnd() % (r - l + 1) + l;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	// int n = 5;
	// std::vector<int> a(n + 2);
	// for (int i = 1; i <= n; i++) {
	// 	a[i] = rng(1, 10);
	// }

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << a[i] << " \n"[i == n];
	// }

	std::vector<std::vector<int>> f(n + 2, std::vector<int>(30));
	for (int i = 1; i <= n; i++) {
		f[i][0] = a[i];
	}
	for (int j = 1; j <= log(n) / log(2); j++) {
		for (int i = 1; i <= n - (1 << j) + 1; i++) {
			f[i][j] = std::min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
		}
	}

	auto minr = [&](int l, int r) {
		int x = log(r - l + 1) / log(2);
		return std::min(f[l][x], f[r - (1 << x) + 1][x]);
	};

	std::vector<int> premax(n + 2), sufmax(n + 2);
	for (int i = 1; i <= n; i++) {
		premax[i] = std::max(premax[i - 1], a[i]);
	}
	for (int i = n; i >= 1; i--) {
		sufmax[i] = std::max(sufmax[i + 1], a[i]);
	}

	int x = 0, y = 0, z = 0;

	auto check = [&](int x, int y, int z) -> bool {
		// 1 ~ x, x + 1 ~ x + y, x + y + 1 ~ x + y + z
		int p1 = premax[x], p2 = sufmax[x + y + 1], p3 = minr(x + 1, x + y);
		if (p2 != p1 || p3 != p1) {
			return 0;
		}
		return 1;
	};

	int r = n + 1;
	for (int l = 1; l <= n; l++) {
		if (premax[l] == premax[l - 1]) {
			continue;
		}
		while (sufmax[r - 1] < premax[l] && r >= l + 3) {
			r--;
			// std::cerr << l << " " << r << '\n';
		}

		if (sufmax[r - 1] == premax[l]) {
			r--;
		}

		if (premax[l] > sufmax[r]) {
			continue;
		}

		// std::cerr << "1 .. " << l << " " << r << " .. n" << '\n';
		if (r <= l + 1) {
			continue;
		}
		int basel = premax[l], baser = sufmax[r];
		int ll = l, rr = r;
		while (premax[ll + 1] == basel && rr >= ll + 3) {
			ll++;
		}
		while (sufmax[rr - 1] == baser && rr >= ll + 3) {
			rr--;
		}

		// std::cerr << "?" << '\n';
		// std::cerr << ll + 1 << " " << rr - 1 << '\n';

		if (minr(ll + 1, rr - 1) == premax[l]) {
			std::cout << "YES" << '\n';
			std::cout << ll << " " << rr - ll - 1 << " " << n - rr + 1 << '\n';
			x = ll, y = rr - ll - 1, z = n - rr + 1;
			assert(check(x, y, z));
			return;
		}

		if (minr(ll + 1, rr - 1) < premax[l]) {
			continue;
		}

		// minr(ll + 1, rr - 1) > premax[l]

		for (int i = ll; i > l; i--) {
			// std::cerr << i << " " << ll << " " << l << '\n';
			if (a[i] < premax[l]) {
				break;
			}
			assert(a[i] == premax[l]);
			if (premax[i - 1] == a[i] && sufmax[i + 1] == a[i]) {
				// 1 ~ i - 1, i ~ i, i + 1 ~ n
				std::cout << "YES" << '\n';
				std::cout << i - 1 << " " << 1 << " " << n - i << '\n';
				x = i - 1, y = 1, z = n - i;
				assert(check(x, y, z));
				return;
			}
			if (premax[i - 1] == minr(i, rr - 1) && minr(i, rr - 1) == sufmax[rr]) {
				std::cout << "YES" << '\n';
				std::cout << i - 1 << " " << rr - i << " " << n - rr + 1 << '\n';
				return;
			}
			return;
		}
		for (int i = rr; i < r; i++) {
			// std::cerr << i << " " << rr << " " << r << '\n';
			if (a[i] < premax[l]) {
				break;
			}
			assert(a[i] == premax[l]);
			if (premax[i - 1] == a[i] && sufmax[i + 1] == a[i]) {
				std::cout << "YES" << '\n';
				std::cout << i - 1 << " " << 1 << " " << n - i << '\n';
				x = i - 1, y = 1, z = n - i;
				assert(check(x, y, z));
				return;
			}
			if (sufmax[i + 1] == minr(ll + 1, i) && minr(ll + 1, i) == premax[ll]) {
				std::cout << "YES" << '\n';
				std::cout << ll << " " << i - ll << " " << n - i << '\n';
				return;
			}
		}	
	}

	int el = 1e9, er = -1;
	for (int i = 1; i <= n; i++) {
		if (premax[i] == sufmax[i]) {
			el = std::min(el, i), er = std::max(er, i);
		}
	}

	// std::cerr << el << " " << er << '\n';

	int cnt = 0;
	for (int i = el + 1; i <= er - 1; i++) {
		if (a[i] == premax[el]) {
			std::cout << "YES" << '\n';
			std::cout << i - 1 << " " << 1 << " " << n - i << '\n';
			x = i - 1, y = 1, z = n - i;
			assert(check(x, y, z));
			return;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = i + 2; j <= n; j++) {
	// 		// 1 ~ i, i + 1 ~ j - 1, j ~ n
	// 		int p1 = premax[i], p2 = sufmax[j], p3 = minr(i + 1, j - 1);
	// 		if (p1 == p2 && p2 == p3) {
	// 			std::cerr << "find" << 1 << "~" << i << " " << i + 1 << "~" << j - 1 << " " << j << "~" << n << '\n';
	// 			exit(-1);
	// 		}
	// 	}
	// }

	std::cout << "NO" << '\n';
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