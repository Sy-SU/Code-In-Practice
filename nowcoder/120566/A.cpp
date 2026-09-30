#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	i64 x, y;
	bool operator < (Node n) const {
		return y * n.x < x * n.y;
	}
};

void solve() {
	int n, w;
	std::cin >> n >> w;

	std::priority_queue<Node> pq;
	for (int i = 1; i <= n; i++) {
		i64 x, y;
		std::cin >> x >> y;

		pq.push({x, y});
	}

	for (int i = 1; i <= w; i++) {
		auto [x, y] = pq.top();
		pq.pop();

		if (y > 0) {
			y--;
		}
		pq.push({x, y});
	}

	double ans = 0;
	while (!pq.empty()) {
		auto [x, y] = pq.top();
		pq.pop();

		ans += sqrtl(x * x + y * y);
	}
	std::cout << std::fixed << std::setprecision(12) << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}