#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

struct SEGMENT {
	int l, r;
	bool operator > (SEGMENT s) const {
		return r == s.r ? l > s.l : r > s.r;
	}
};

void solve() {
	int n, a, b, c;
	std::cin >> n >> a >> b >> c;

	std::vector<SEGMENT> x(n + 1), y(n + 1), z(n + 1);

	for (int i = 1; i <= n; i++) {
		int x1, y1, z1, x2, y2, z2;
		std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

		if (x1 > x2) {
			std::swap(x1, x2);
		}
		if (y1 > y2) {
			std::swap(y1, y2);
		}
		if (z1 > z2) {
			std::swap(z1, z2);
		}

		x[i] = {x1, x2}, y[i] = {y1, y2}, z[i] = {z1, z2};
	}

	auto calc = [&](std::vector<SEGMENT> seg, int sz) -> int {
		std::sort(seg.begin() + 1, seg.end(), [](SEGMENT s1, SEGMENT s2) {
			return s1.l == s2.l ? s1.r < s2.r : s1.l < s2.l;
		});

		int ans = 0;

		std::priority_queue<SEGMENT, std::vector<SEGMENT>, std::greater<SEGMENT>> pq;
		for (int i = 1; i <= sz; i++) {
			// std::cerr << seg[i].l << " " << seg[i].r << '\n';
			while (!pq.empty() && pq.top().r < seg[i].l) {
				pq.pop();
			}

			pq.push(seg[i]);

			ans = std::max(ans, (int)pq.size());
		}

		return ans;
	};

	std::cout << std::max({calc(x, n), calc(y, n), calc(z, n)}) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}