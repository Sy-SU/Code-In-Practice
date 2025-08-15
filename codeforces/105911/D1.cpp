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
	int n;
	std::cin >> n;

	std::vector<SEGMENT> x(n + 1);

	for (int i = 1; i <= n; i++) {
		int l, r;
		std::cin >> l >> r;

		x[i] = {l, r};
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
	
	std::cout << calc(x, n) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}