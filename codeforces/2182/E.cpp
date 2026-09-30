#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int x;
	i64 more;
};

void solve() {
	int n, m;
	i64 k;
	std::cin >> n >> m >> k;

	std::vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end());

	std::vector<Node> node(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		i64 y, z;
		std::cin >> x >> y >> z;

		node[i] = {x, z - y};
		k -= y;
	}

	std::sort(node.begin() + 1, node.end(), [](Node n1, Node n2) {
		return n1.x < n2.x;
	});

	int ans = 0;
	std::vector<int> live(n + 1, 1);

	std::priority_queue<std::pair<i64, int>> pq; // [more, ind]
	int ptr = 0;
	for (int i = 1; i <= m; i++) {
		while (ptr < n && node[ptr + 1].x <= a[i]) {
			ptr++;
			pq.push({node[ptr].more, ptr});
		}
		if (node[ptr].x > a[i]) {
			break;
		}
		if (pq.empty()) {
			continue;
		}
		// std::cerr << "i = " << i << " ptr = " << ptr << '\n';

		auto max = pq.top();
		pq.pop();
		ans++;
		live[max.second] = 0;
		// std::cerr << "dropped - ind" << max.second << " " << "more cost = " << max.first << "\n";
	}

	std::vector<i64> rest;
	for (int i = 1; i <= n; i++) {
		if (live[i] == 0) {
			continue;
		}
		rest.push_back(node[i].more);
	}

	std::sort(rest.begin(), rest.end());
	for (auto cost : rest) {
		if (cost > k) {
			break;
		}
		k -= cost, ans++;
	}
	std::cout << ans << '\n';
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