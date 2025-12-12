#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::vector<std::pair<int, int>> vec(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> vec[i].first >> vec[i].second;
	}

	std::cout << vec[2].first + vec[1].first - vec[0].first << " " << vec[2].second + vec[1].second - vec[0].second << '\n';
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