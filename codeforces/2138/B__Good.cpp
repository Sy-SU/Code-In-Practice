#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	while (q--) {
		int l, r;
		std::cin >> l >> r;

		std::vector<std::pair<int, int>> org;
		for (int i = l; i <= r; i++) {
			org.push_back({a[i], i - l});
		}
		std::sort(org.begin(), org.end());

		bool isok = 1;
		for (int i = 0; i < org.size(); i++) {
			if (std::abs(org[i].second - i) >= 2) {
				isok = 0;
			}
		}
		std::cout << (isok ? "YES" : "NO") << '\n';
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