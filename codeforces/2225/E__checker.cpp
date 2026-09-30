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

	std::sort(vec.begin() + 1, vec.end());

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << vec[i].first << " " << vec[i].second << '\n';
	// }

	int d = ceil(1.732 * r);

	int idx = 0;

	// int basx = rng(1, 1000), basy = rng(1, 1000);

	std::map<std::pair<int, int>, bool> vis;

	std::vector<std::pair<int, int>> cir;
	for (int x = -200; x <= 200; x += d) {
		int cnt = 0;
		for (int y = -200; y <= 200; y += r) {
			cnt++;
			// if (cnt == 5) {
			// 	cnt--;
			// }
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
				if (vec[mid].first <= x) {
					left = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}

			lo = 1, hi = n;
			int right = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (vec[mid].first >= x) {
					right = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}

			bool isok = 0;
			for (int ind = left; ind <= right; ind++) {
				auto [tx, ty] = vec[ind];
				i64 dis = (tx - x) * 1ll * (tx - x) + (ty - y) * 1ll * (ty - y);
				// std::cerr << dis << '\n';
				if (dis <= r * 1ll * r) {
					isok = 1;
					break;
				}
			}
			// if (isok == 1) {
				cir.push_back({x, y});
			// }
		}
		cnt = 0;
		idx++;
	}

	std::cout << cir.size() << '\n';
	for (auto [x, y] : cir) {
		// std::cout << x << " " << y << '\n';
		for (int i = -200; i <= 200; i++) {
			for (int j = -200; j <= 200; j++) {
				if ((i - x) * 1ll * (i - x) + (j - y) * 1ll * (j - y) <= r * r) {
					vis[{i, j}] = 1;
				}
			}
		}
	}
	std::cout << (int)vis.size() * 1.0 / 160000 << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}