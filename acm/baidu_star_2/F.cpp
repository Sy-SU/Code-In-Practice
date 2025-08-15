#include <bits/stdc++.h>

using i64 = long long;

struct NODE {
	int ind, dis;
	bool operator > (const NODE &n) const {
		return dis > n.dis;
	}
};

void solve() {
	int q, k;
	std::cin >> q >> k;

	std::vector<int> dist(1 << k, 1e9);

	while (q--) {
		int o, x;
		std::cin >> o >> x;

		if (o == 1) {
			std::priority_queue<NODE, std::vector<NODE>, std::greater<NODE>> pq;
			pq.push({x, 0});
			dist[x] = 0;
			
			while (!pq.empty()) {
				auto [now, d] = pq.top();
				pq.pop();

				for (int b = 0; b < k; b++) {
					int xr = (1 << b);
					int to = now ^ xr;

					if (dist[to] > dist[now] + 1) {
						dist[to] = dist[now] + 1;
						pq.push({to, dist[to]});
					}
				}
			}
		} else {
			std::cout << dist[x] << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}