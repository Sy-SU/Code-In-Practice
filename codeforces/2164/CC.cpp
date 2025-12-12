#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int b, c;
	bool operator > (Node n) const {
		return c > n.c;
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 1), b(m + 1), c(m + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> c[i];
	}

	std::vector<Node> mon(m + 1);
	for (int i = 1; i <= m; i++) {
		mon[i] = {b[i], c[i]};
	}

	// std::sort(a.begin() + 1, a.end(), std::greater<int>());
	std::sort(mon.begin() + 1, mon.end(), [](Node n1, Node n2) {
		return n1.b < n2.b;
	});

	std::priority_queue<Node> lheap;
	std::priority_queue<Node, std::vector<Node>, std::greater<Node>> rheap;

	for (int i = 1; i <= m; i++) {
		lheap.push(mon[i]);
	}

	std::priority_queue<int> pa;
	for (int i = 1; i <= n; i++) {
		pa.push(a[i]);
	}

	int cnt = 0, ptr = 0;
	while (!pa.empty()) {
		// a[i]
		int now = pa.top();
		pa.pop();

		while (!lheap.empty() && lheap.top().c >= now) {
			auto tp = lheap.top();
			lheap.pop();

			rheap.push(tp);
		}

		if (!rheap.empty()) {
			auto tp = rheap.top();
			rheap.pop();
			if (tp.b > now) {
				pa.push(now);
			} else {
				cnt++;
				pa.push(std::max(now, ))
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