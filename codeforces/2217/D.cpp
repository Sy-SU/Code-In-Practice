#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	
	std::vector<int> b(n + 2), p(k + 2), vp(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}
	for (int i = 1; i <= k; i++) {
		std::cin >> p[i];
		vp[p[i]] = 1;
	}
	p[k + 1] = n + 1;
	b[n + 1] = -1;

	std::vector<int> a;
	a.push_back(-1);

	int l = 1;
	for (int i = 1; i <= n; i++) {
		if (b[i] != b[i + 1]) {
			// l -> r
			int tp = 0;
			for (int j = l; j <= i; j++) {
				if (b[j] == b[p[1]]) {
					tp = 1;
				}
				if (vp[j]) {
					tp = 2;
					break;
				}
			}
			a.push_back(tp);

			l = i + 1;
		}
	}

	n = (int)a.size() - 1;

	std::cerr << "a = " << '\n';
	for (int i = 1; i <= n; i++) {
		std::cerr << a[i] << " \n"[i == n];
	}

	int cnt1 = 0;
	for (int i = 1; i <= n; i++) {
		cnt1 += a[i] == 0;
	}
	if (cnt1 == 0) {
		std::cout << 0 << '\n';
		return;
	}

	int ans = 0;

	std::vector<int> s;

	int lst1 = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			// lst1 -> i
			if (lst1 != -1) {
				int len = i - lst1 - 1;
				if (len > 1) {
					ans += (len + 1) / 2;
					while (!s.empty() && s.back() != 1) {
						s.pop_back();
					}
					s.push_back(2);
					s.push_back(1);
				} else {
					if (!s.empty() && s.back() != 2) {
						s.push_back(0);
					}
					s.push_back(1);
				}
			} else {
				s.push_back(1);
			}
			lst1 = i;
		}
	}

	int len = n - lst1;
	if (len > 1) {
		ans += (len + 1) / 2;
		while (!s.empty() && s.back() != 1) {
			s.pop_back();
		}
		s.push_back(2);
	} else if (len == 1) {
		if (!s.empty() && s.back() != 2) {
			s.push_back(0);
		}
		s.push_back(1);
	}
	// 0 -> 1

	std::cerr << "ans = " << ans << '\n';
	std::cerr << "res = ";
	for (auto num : s) {
		std::cerr << num << " ";
	}
	std::cerr << '\n' << '\n';

	// auto a = b;
	// for (int i = 1; i <= n; i++) {
	// 	a[i] = b[i] != b[p[1]];
	// }

	// for (int i = 1; i <= n; i++) {
	// 	std::cerr << a[i] << " \n"[i == n];
	// }

	// std::vector<int> seg;
	// for (int i = 0; i <= k; i++) {
	// 	// p[i] + 1 -> p[i + 1] - 1
	// 	int cnt = 0;
	// 	for (int j = p[i] + 1; j <= p[i + 1] - 1; j++) {
	// 		if (a[j] == 1 && a[j - 1] == 0) {
	// 			cnt++;
	// 		}
	// 	}
	// 	seg.push_back(cnt);
	// }
	// int sz = seg.size();
	// for (int i = 0; i < sz; i++) {
	// 	std::cerr << seg[i] << " \n"[i == sz - 1];
	// }
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