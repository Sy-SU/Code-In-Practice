#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::map<i64, std::vector<int>> pos;
	for (int i = 1; i <= n; i++) {
		pos[a[i]].push_back(i);
	}

	int d = pos.size(); 

	std::set<int> st;

	int cnt = 0;

	for (auto [val, p] : pos) {
		int sz = p.size();
		int l = p[0], r = p[0];
		for (int i = 1; i < sz; i++) {
			if (p[i] != p[i - 1] + 1) {
				st.insert(l - 1), st.insert(l), st.insert(l + 1);
				st.insert(r - 1), st.insert(r), st.insert(r + 1);
				l = p[i], r = p[i];
				cnt++;
			} else {
				r = p[i];
			}
		}

		if (l != p[0]) {
			st.insert(l - 1), st.insert(l), st.insert(l + 1);
			st.insert(r - 1), st.insert(r), st.insert(r + 1);
		}
	}

	if (cnt > 4) {
		std::cout << "NO" << '\n';
		return;
	}

	std::vector<int> v;
	for (auto num : st) {
		if (1 <= num && num <= n) {
			v.push_back(num);
		}
	}

	if (v.empty()) {
		std::cout << "YES" << '\n';
		return;
	}

	// for (auto num : v) {
	// 	std::cerr << num << '\n';
	// }

	int sz = v.size();
	for (int i = 0; i < sz; i++) {
		for (int j = i + 1; j < sz; j++) {
			int p1 = v[i], p2 = v[j];
			std::swap(a[p1], a[p2]);

			bool isok = 1;

			int t = 0;
			for (int k = 2; k <= n; k++) {
				if (a[k] != a[k - 1]) {
					t++;				
				}
			}

			if (t == d - 1) {
				std::cout << "YES" << '\n';
				return;
			}

			std::swap(a[p1], a[p2]);
		}
	}
	std::cout << "NO" << '\n';
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