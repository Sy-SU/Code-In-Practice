#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> d(n + 1); // {dep, ind}
	for (int i = 1; i <= n; i++) {
		std::cout << "? " << i << " " << n << " ";
		for (int j = 1; j <= n; j++) {
			std::cout << j << " ";
		}
		std::cout << std::endl;

		int dep;
		std::cin >> dep;

		d[i] = {dep, i};
	}

	// std::sort(d.begin() + 1, d.end(), std::greater<std::pair<int, int>>());

	// int maxd = d[1].first;

	std::vector<std::vector<int>> de(n + 1);
	for (int i = 1; i <= n; i++) {
		de[d[i].first].push_back(d[i].second);
	}

	std::vector<int> path;
	int now = -1;
	for (int i = n; i >= 2; i--) {
		if (de[i].empty()) {
			continue;
		}

		if (now == -1) {
			now = de[i][0];
		}
		path.push_back(now);

		for (auto to : de[i - 1]) {
			std::cout << "? " << now << " " << 2 << " " << now << " " << to << std::endl;

			int ok;
			std::cin >> ok;

			if (ok == 2) {
				now = to;
				break;
			}
		}
	}
	// std::cerr << now << std::endl;

	path.push_back(now);

	if (now == -1) {
		std::cout << "! " << 1 << " " << 1 << std::endl;

		return;
	}

	std::cout << "! " << path.size() << " ";
	for (auto p : path) {
		std::cout << p << " ";
	}
	std::cout << std::endl;
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