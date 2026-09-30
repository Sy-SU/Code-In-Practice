#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	auto h = a;

	if (2 * m > n) {
		std::cout << -1 << '\n';
		return;
	}

	std::vector<std::pair<i64, int>> node(n + 1);
	for (int i = 1; i <= n; i++) {
		node[i] = {a[i], i};
	}

	std::sort(node.begin() + 1, node.end());

	if (m == 0) {
		i64 max = node[n].first, res = 0;
		for (int i = 1; i < n; i++) {
			res += node[i].first;
		}

		if (max <= res) {
			std::vector<std::pair<int, int>> op;
			i64 sum = 0, r = n;
			for (int i = n - 1; i >= 1; i--) {
				if (sum + node[i].first < node[n].first) {
					op.push_back({node[i].second, node[n].second});
					sum += node[i].first;
				} else {
					r = i;
					break;
				}
			}
			for (int i = 1; i < r; i++) {
				op.push_back({node[i].second, node[i + 1].second});
			}
			op.push_back({node[r].second, node[n].second});

			std::cout << op.size() << '\n';
			for (auto [x, y] : op) {
				assert(h[x] > 0);
				assert(h[y] > 0);
				h[x] -= a[y], h[y] -= a[x];
				std::cout << x << " " << y << '\n';
			}
		} else {
			std::cout << -1 << '\n';
		}
		return;
	}

	if (m == 1) {
		std::cout << n - 1 << '\n';
		for (int i = 1; i < n; i++) {
			int x = node[i].second, y = node[i + 1].second;
			assert(h[x] > 0);
			assert(h[y] > 0);
			h[x] -= a[y], h[y] -= a[x];
			std::cout << node[i].second << " " << node[i + 1].second << '\n';
		}
		return;
	}

	std::vector<std::pair<int, int>> op;
	op.push_back({node[n].second, node[1].second});

	int l = n - 2 * m + 2, r = n - 1;
	while (l < r) {
		op.push_back({node[r].second, node[l].second});
		l++, r--;
	}

	for (int i = 2; i < n - 2 * m + 1; i++) {
		op.push_back({node[i].second, node[i + 1].second});
	}
	if (n > 2 * m) {
		op.push_back({node[n - 2 * m + 1].second, node[n].second});
		if (node[n].first - node[1].first > node[n - 2 * m + 1].second) {
			std::cout << op.size() << '\n';
			for (auto [x, y] : op) {
				std::cout << x << " " << y << '\n';
			}
		} else {
			std::cout << -1 << '\n';
		}
	} else {
		std::cout << op.size() << '\n';
		for (auto [x, y] : op) {
			assert(h[x] > 0);
			assert(h[y] > 0);
			h[x] -= a[y], h[y] -= a[x];
			std::cout << x << " " << y << '\n';
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