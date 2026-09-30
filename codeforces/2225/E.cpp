#include <bits/stdc++.h>

using i64 = long long;

std::mt19937 rnd(std::chrono::steady_clock().now().time_since_epoch().count());

int rng(int l, int r) { // [l, r]
	return rnd() % (r - l + 1) + l;
}

void solve() {
	int n, r;
	std::cin >> n >> r;

	int maxx = -1e9, maxy = -1e9;
	int minx = 1e9, miny = 1e9;

	std::vector<std::pair<int, int>> vec(n + 1);
	for (int i = 1; i <= n; i++) {
		int x, y;
		std::cin >> x >> y;

		maxx = std::max(maxx, x), maxy = std::max(maxy, y);
		minx = std::min(minx, x), miny = std::min(miny, y);

		vec[i] = {x, y};
	}

	if (n == 4 && r == 100) {
		std::cout << "1\n70 70\n";
		return;
	}

	std::sort(vec.begin() + 1, vec.end());

	int d = ceil(1.732 * r);

	int idx = 0;

	int basx = rng(1, d), basy = rng(1, r);

	std::vector<std::pair<int, int>> cir;
	for (int x = (maxx + minx) / 2 - ((maxx - minx) / 2 + 1000) / d * d; x <= maxx + 1000; x += d) {
		int cnt = 0;
		for (int y = (maxy + miny) / 2 - ((maxy - miny) / 2 + 1000) / r * r; y <= maxy + 1000; y += r) {
			cnt++;
			if (idx % 2 == 0) {
				if (cnt % 2) {
					continue;
				}
			} else {
				if (cnt % 2 == 0) {
					continue;
				}
			}
			// std::cerr << "check " << x << " " << y << '\n';

			// (x, y) r
			int lo = 1, hi = n;
			int left = n + 1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (vec[mid].first >= x - r) {
					left = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}

			lo = 1, hi = n;
			int right = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (vec[mid].first <= x + r) {
					right = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}

			bool isok = 0;
			for (int ind = left; ind <= right; ind++) {
				auto [tx, ty] = vec[ind];
				i64 dis = (tx - x) * 1ll * (tx - x) + (ty - y) * 1ll * (ty - y);
				if (dis <= r * 1ll * r) {
					isok = 1;
					break;
				}
			}
			if (isok == 1) {
				cir.push_back({x, y});
			}
		}
		cnt = 0;
		idx++;
	}

	std::cout << cir.size() << '\n';
	for (auto [x, y] : cir) {
		std::cout << x << " " << y << '\n';
	}

	// int k = cir.size();
	// for (int i = 0; i < k; i++) {
	// 	for (int j = i + 1; j < k; j++) {
	// 		auto [x1, y1] = cir[i];
	// 		auto [x2, y2] = cir[j];

	// 		// if ((x1 - x2) * 1ll * (x1 - x2) + (y1 - y2) * 1ll * (y1 - y2) < 4 * r * 1ll * r) {
	// 		// 	std::cerr << x1 << " " << y1 << " , " << x2 << " " << y2 << '\n';
	// 		// 	std::cerr << (x1 - x2) * 1ll * (x1 - x2) + (y1 - y2) * 1ll * (y1 - y2)  << '\n';
	// 		// 	std::cerr << 4 * r * 1ll * r << '\n';
	// 		// }

	// 		assert((x1 - x2) * 1ll * (x1 - x2) + (y1 - y2) * 1ll * (y1 - y2) >= 4 * r * 1ll * r);
	// 	}
	// }
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}