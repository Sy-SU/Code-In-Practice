#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> vec(n + 1);
	std::vector<int> cnt(2 * n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> vec[i].first >> vec[i].second;
		if (vec[i].first == vec[i].second) {
			cnt[vec[i].first]++;
		}
	}

	std::vector<int> pre(2 * n + 1, 0);
	for (int i = 1; i <= 2 * n; i++) {
		pre[i] = pre[i - 1] + (cnt[i] == 0);
	}

	// for (int i = 1; i <= 2 * n; i++) {
	// 	std::cerr << cnt[i] << " \n"[i == 2 * n];
	// }

	for (int i = 1; i <= n; i++) {
		if (vec[i].first == vec[i].second) {
			std::cout << (cnt[vec[i].first] == 1);
		} else {
			std::cout << ((pre[vec[i].second] - pre[vec[i].first - 1]) > 0);
		}
		
	}
	std::cout << '\n';

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