#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int fa[N];

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}

void solve() {
	int n;
	std::cin >> n;
	
	std::vector<std::pair<int, int>> vec(n + 1, {0, 0});
	for (int i = 1; i <= n; i++) {
		std::cin >> vec[i].first >> vec[i].second;
	}

	int lo = 0, hi = 1e9;
	int ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&]() -> bool {
			for (int i = 1; i <= n; i++) {
				fa[i] = i;
			}

			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (std::abs(vec[i].first - vec[j].first) + std::abs(vec[i].second - vec[j].second) <= 2 * mid) {
						merge(i, j);
					}
				}
			}

			for (int i = 1; i <= n; i++) {
				if (find(i) != find(1)) {
					return 0;
				}
			}

			return 1;
		};

		if (check()) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}