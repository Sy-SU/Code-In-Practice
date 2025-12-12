#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int b, c;
	bool operator < (Node n) const {
		return c < n.c;
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

	std::sort(a.begin() + 1, a.end());

	std::vector<Node> mon(m + 1);
	for (int i = 1; i <= m; i++) {
		mon[i] = {b[i], c[i]};
	}

	std::vector<Node> mon1, mon2;
	for (int i = 1; i <= m; i++) {
		if (mon[i].c == 0) {
			mon2.push_back(mon[i]);
		} else {
			mon1.push_back(mon[i]);
		}
	}

	std::sort(mon1.begin(), mon1.end(), [](Node n1, Node n2) {
		return n1.b < n2.b;
	});

	for (auto &[x, y] : mon1) {
		y = std::max(x, y);
	}

	int cnt = 0;

	std::priority_queue<int, std::vector<int>, std::greater<int>> pa, res;
	for (int i = 1; i <= n; i++) {
		pa.push(a[i]);
	}

	for (int i = 0; i < (int)mon1.size(); i++) {
		while (!pa.empty()) {
			if (pa.top() >= mon1[i].b) {
				int now = pa.top();
				pa.pop();
				cnt++;
				pa.push(std::max(now, mon1[i].c));
				break;
			} else {
				res.push(pa.top());
				pa.pop();
			}
		}
	}

	while (!res.empty()) {
		pa.push(res.top());
		res.pop();
	}

	std::sort(mon2.begin(), mon2.end(), [](Node n1, Node n2) {
		return n1.b < n2.b;
	});

	for (int i = 0; i < (int)mon2.size(); i++) {
		while (!pa.empty()) {
			if (pa.top() >= mon2[i].b) {
				pa.pop();
				cnt++;
				break;
			} else {
				pa.pop();
			}
		}
	}
 
	std::cout << cnt << '\n';
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