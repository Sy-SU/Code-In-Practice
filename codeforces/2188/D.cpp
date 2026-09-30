#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	i64 ans;
	i64 p, q;
};

void solve() {
	i64 x, y;
	std::cin >> x >> y;

	auto calc = [&](i64 x, i64 y) -> Node {
		// p & y == 0
		// min |x - p|

		// i64 ans = 1e18;

		// Node res = {ans, -1, -1};

		// for (int p = std::max(0ll, x - 100000000); p <= x + 100000000; p++) {
		// 	if (p & y) {
		// 		continue;
		// 	}

		// 	if (ans > std::abs(p - x)) {
		// 		ans = std::abs(p - x);
		// 		res = {ans, p, y};
		// 	}
		// }
		i64 now = ((1ll << 31) - 1) ^ y;

		i64 p1 = 0;
		for (int b = 30; b >= 0; b--) {
			// 比 x 小的同时尽可能大
			if (((now >> b) & 1) == 0) {
				continue;
			}
			if ((1 << b) > x) {
				continue; // 不能选
			} else {
				if (p1 + (1 << b) <= x) {
					p1 += (1 << b);
				}
			}
		}

		i64 ans1 = std::abs(p1 - x);

		i64 p2 = now;

		// i64 tmp1 = 1e18;
		// for (int b = 30; b >= 0; b--) {
		// 	// 比 x 大的同时尽可能小
		// 	if (((now >> b) & 1) == 0) {
		// 		continue;
		// 	}
		// 	if ((1 << b) >= x) {
		// 		tmp1 = std::min(tmp1, (1 << b) * 1ll);
		// 	}
		// }
		// p2 = tmp1;

		for (int b = 30; b >= 0; b--) {
			// 比 x 大的同时尽可能小
			if (((now >> b) & 1) == 0) {
				continue;
			}
			if ((p2 ^ (1 << b)) < x) {
				continue;
			} else {
				p2 ^= (1 << b);
			}
		}

		i64 ans2 = std::abs(p2 - x);

		Node res;
		if (ans1 < ans2) {
			res = {ans1, p1, y};
		} else {
			res = {ans2, p2, y};
		}

		return res;
	};

	auto r1 = calc(x, y);
	auto r2 = calc(y, x);

	int p = -1, q = -1;
	if (r1.ans > r2.ans) {
		// std::cout << r2.p << " " << r2.q << '\n';
		p = r2.q, q = r2.p;
	} else {
		// std::cout << r1.p << " " << r1.q << '\n';
		p = r1.p, q = r1.q;
	}
	std::cout << p << " " << q << '\n';
	// std::cerr << "ans = " << std::abs(p - x) + std::abs(q - y) << '\n';

	// i64 ans = 1e9;
	// std::vector<std::pair<int, int>> vec;
	// for (i64 p = 0; p <= 10000; p++) {
	// 	for (i64 q = 0; q <= 10000; q++) {
	// 		if (p & q) {
	// 			continue;
	// 		}
	// 		if (ans > std::abs(x - p) + std::abs(y - q)) {
	// 			ans = std::abs(x - p) + std::abs(y - q);
	// 			vec.clear();
	// 			vec.push_back({p, q});
	// 		} else if (ans == std::abs(x - p) + std::abs(y - q)) {
	// 			vec.push_back({p, q});
	// 		}
	// 	}
	// }

	// // std::cerr << ans << " " << std::abs(p - x) + std::abs(q - y) << "\n";
	// assert(ans == std::abs(p - x) + std::abs(q - y));

	// std::cout << "x = " << x << " " << " y = " << y << '\n';
	// std::cout << "ans = " << ans << '\n';
	// for (auto [p, q] : vec) {
	// 	if (q == y || p == x) {
	// 		std::cout << p << " " << q << '\n';
	// 		std::cerr << "del = " << std::max(std::abs(p - x), std::abs(q - y)) << '\n';
	// 		return;
	// 	}
	// }
	// std::cout << "failed" << '\n';
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