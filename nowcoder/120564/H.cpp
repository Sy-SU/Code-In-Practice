#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int x, y;
	i64 bonus;

	bool operator < (const Node &n) const {
		return bonus < n.bonus;
	}
};

void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;

	std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];	
		}
	}

	std::vector<std::vector<i64>> bonus(n + 1, std::vector<i64>(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int x = i - 2; x <= i + 2; x++) {
				for (int y = j - 2; y <= j + 2; y++) {
					if (x >= 1 && x <= n && y >= 1 && y <= m && std::abs(x - i) + std::abs(y - j) <= 2) {
						bonus[i][j] += a[x][y];
					}
				}
			}
		}
	}

	std::priority_queue<Node> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pq.push({i, j, bonus[i][j]});
			// std::cerr << "push" << i << " " << j << " " << bonus[i][j] << '\n';
		}
	}

	while (q--) {
		int x, y;
		i64 z;
		std::cin >> x >> y >> z;

		for (int i = x - 2; i <= x + 2; i++) {
			for (int j = y - 2; j <= y + 2; j++) {
				if (i >= 1 && i <= n && j >= 1 && j <= m && std::abs(x - i) + std::abs(y - j) <= 2) {
					bonus[i][j] += z;
					pq.push({i, j, bonus[i][j]});
					// std::cerr << "push" << i << " " << j << " " << bonus[i][j] << '\n';
				}
			}
		}

		auto [i, j, v] = pq.top();
		std::cout << i << " " << j << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}