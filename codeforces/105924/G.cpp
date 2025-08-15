#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> in(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;

		in[u]++, in[v]++;
	}

	std::vector<int> need;
	for (int i = 1; i <= n; i++) {
		if (in[i] % 2) {
			need.push_back(i);
		}
	}

	// if (need.size() == 2) {
	// 	std::cout << need[0] << " " << need[1] << '\n';
	// 	return;
	// }

	std::cout << need.size() / 2 << '\n';
	for (int i = 1; i < (int)need.size(); i += 2) {
		std::cout << need[i - 1] << " " << need[i] << '\n';
	}
	// std::cout << need[0] << " " << need[(int)need.size() - 1] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}