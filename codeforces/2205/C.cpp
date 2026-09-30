#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> l(n + 1);
	std::vector<std::vector<int>> a;
	a.push_back({});
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i];
		std::vector<int> h(l[i]), hh;
		for (int j = 0; j < l[i]; j++) {
			std::cin >> h[j];
		}

		std::map<int, bool> v;
		for (int j = l[i] - 1; j >= 0; j--) {
			if (!v[h[j]]) {
				hh.push_back(h[j]);
				v[h[j]] = 1;
			}
		}

		std::reverse(hh.begin(), hh.end());

		a.push_back(hh);
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j < (int)a[i].size(); j++) {
	// 		std::cerr << a[i][j] << " \n"[j == (int)a[i].size() - 1];
	// 	}
	// }

	std::map<int, bool> vis;

	auto cmp = [&](std::vector<int> &a1, std::vector<int> &a2) -> bool {
		std::vector<int> p1, p2;

		for (int i = (int)a1.size() - 1; i >= 0; i--) {
			int e = a1[i];
			if (!vis[e]) {
				p1.push_back(e);
			}
		}

		for (int i = (int)a2.size() - 1; i >= 0; i--) {
			int e = a2[i];
			if (!vis[e]) {
				p2.push_back(e);
			}
		}

		if (p1.empty()) {
			return 0;
		}
		if (p2.empty()) {
			return 1;
		}

		int l1 = p1.size(), l2 = p2.size();
		for (int i = l1; i < std::max(l1, l2); i++) {
			p1.push_back(0);
		}
		for (int i = l2; i < std::max(l1, l2); i++) {
			p2.push_back(0);
		}

		for (int i = 0; i < std::max(l1, l2); i++) {
			if (p1[i] != p2[i]) {
				return p1[i] < p2[i];
			}
		}

		return false;
	};

	std::vector<int> output;

	for (int r = 1; r <= n; r++) {
		// std::cerr << r << '\n';

		std::vector<int> best;

		for (int i = 1; i <= n; i++) {
			if (cmp(a[i], best)) {
				best = a[i];
			}
		}

		for (int i = (int)best.size() - 1; i >= 0; i--) {
			if (!vis[best[i]]) {
				vis[best[i]] = 1;
				output.push_back(best[i]);
				// std::cerr << "ot" << best[i] << "\n";
			}
		}
	}

	for (auto o : output) {
		std::cout << o << " ";
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