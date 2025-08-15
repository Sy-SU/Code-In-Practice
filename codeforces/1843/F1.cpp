#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int q;
	std::cin >> q;

	int idx = 1;
	std::vector<std::vector<int>> edge(q + 1);
	std::vector<int> p(q + 1, 0);
	std::vector<std::pair<std::pair<int, int>, int>> pre(q + 1);
	std::vector<std::pair<int, int>> del(q + 1);
	p[1] = 1;

	while (q--) {
		char op;
		std::cin >> op;
		if (op == '+') {
			int v, x;
			std::cin >> v >> x;
			idx++;
			edge[idx].push_back(v), edge[v].push_back(idx);
			p[idx] = x;
			// v -> idx
			auto [range, presum] = pre[v];
			auto [lo, hi] = range;
			presum += p[idx];
			lo = std::min(lo, presum), hi = std::max(hi, presum);
			pre[idx] = {{lo, hi}, presum};
		} else {
			int u, v, k;
			std::cin >> u >> v >> k;
			assert(u == 1);
			auto [range, presum] = pre[v];
			auto [lo, hi] = range;
			if (k <= hi - lo && k >= lo - hi) {
				std::cout << "YES" << '\n';
			} else {
				std::cout << "NO" << '\n';
			}
		}
	}
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