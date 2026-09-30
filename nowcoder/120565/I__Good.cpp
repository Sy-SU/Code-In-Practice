#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	i64 h;
	std::cin >> n >> m >> h;

	std::vector<std::pair<int, i64>> op(m + 1);
	for (int i = 1; i <= m; i++) {
		int p;
		i64 f;
		std::cin >> p >> f;

		op[i] = {p, f};
	} 

	std::vector<i64> he(n + 1);
	for (int i = 1; i <= m; i++) {
		auto [p, f] = op[i];
		for (int j = 1; j <= n; j++) {
			he[j] += std::max(0ll, f - std::abs(j - p));
			if (he[j] > h) {
				std::cout << "Yes" << '\n';
				std::cout << i << '\n';
				return;
			}
		}
	}
	std::cout << "No" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}