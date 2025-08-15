#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 H;
	std::cin >> n >> H;

	std::vector<std::pair<i64, i64>> h(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> h[i].first;
		h[i].second = i;
	}

	std::sort(h.begin() + 1, h.end(), [&](std::pair<i64, i64> p1, std::pair<i64, i64> p2) {
		return (p1.first * (H - p1.first) < p2.first * (H - p2.first));
	});

	for (int i = 1; i <= n; i++) {
		std::cout << h[i].second << " \n"[i == n];
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