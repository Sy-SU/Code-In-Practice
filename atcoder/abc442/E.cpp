#include <bits/stdc++.h>

using i64 = long long;

#define int long long
constexpr double eps = 1e-18;

bool cmp(std::pair<std::pair<int, int>, int> pp1, std::pair<std::pair<int, int>, int> pp2) {
	auto p1 = pp1.first;
	auto p2 = pp2.first;

	int sta1 = (p1.second > 0 || (p1.second == 0 && p1.first > 0));
	int sta2 = (p2.second > 0 || (p2.second == 0 && p2.first > 0));

	if (sta1 != sta2) {
		return sta1 < sta2;
	}

	return (p1.first * p2.second - p2.first * p1.second) > 0;
}

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<std::pair<std::pair<int, int>, int>> a(n + 1);
	for (int i = 1; i <= n; i++) {
		int x, y;
		std::cin >> x >> y;

		int g = std::gcd(x, y);
		x /= g, y /= g;

		a[i] = {{x, y}, i};
	}

	std::sort(a.begin() + 1, a.end(), cmp);

	std::vector<int> ind(n + 1);
	for (int i = 1; i <= n; i++) {
		ind[a[i].second] = i;
	}

	std::vector<int> pos(n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i].first != a[i - 1].first) {
			pos[i] = i;
		} else {
			pos[i] = pos[i - 1];
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << a[i].first.first << " " << a[i].first.second << " pos = " << pos[i] << '\n';
	// }

	// std::vector<int> cnt(n + 1);
	// for (int i = 1; i <= n; i++) {

	// }

	auto calc = [&](int u, int v) -> int {
		// u -> v
		int cntu = -1;
		int lo = 1, hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (pos[mid] <= pos[u]) {
				lo = mid + 1;
				cntu = mid;
			} else {
				hi = mid - 1;
			}
		}

		int cntv = -1;
		lo = 1, hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (pos[mid] >= pos[v]) {
				hi = mid - 1;
				cntv = mid;
			} else {
				lo = mid + 1;
			}
		}

		// std::cerr << u << "->" << v << '\n';
		// std::cerr << cntu << " " << cntv << '\n';

		int ans = cntu - cntv + 1;
		if (pos[v] > pos[u]) {
			ans = cntu + n - cntv + 1;
		}
		return ans;
	};

	while (q--) {
		int u, v;
		std::cin >> u >> v;

		// a[ind[u]] -> a[ind[v]]

		std::cout << calc(ind[u], ind[v]) << '\n';
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}