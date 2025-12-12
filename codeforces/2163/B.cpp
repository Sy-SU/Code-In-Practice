#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	std::string x;
	std::cin >> x;

	x = " " + x;

	std::vector<int> ind(n + 1);
	for (int i = 1; i <= n; i++) {
		ind[p[i]] = i;
	}

	if (x[ind[1]] == '1' || x[ind[n]] == '1') {
		std::cout << -1 << '\n';
		return;
	}

	bool need = 0;
	for (int i = std::min(ind[1], ind[n]) + 1; i < std::max(ind[1], ind[n]); i++) {
		if (x[i] == '1') {
			need = 1;
		}
	}

	if (need) {
		std::vector<std::pair<int, int>> op;
		op.push_back({std::min(ind[1], ind[n]), std::max(ind[1], ind[n])});

		for (int s = 0; s < 16; s++) {
			int _s = s;
			int indl = std::min(ind[1], ind[n]), indr = std::max(ind[1], ind[n]);
			int tl = 1, tr = 0;
			int l = n, r = 1;
			if (ind[1] < ind[n]) {
				tl = 0, tr = 1;
				l = 1, r = n;
			}

			std::vector<std::pair<int, int>> tmp;

			for (int round = 1; round <= 4; round++) {
				if (_s % 2) {
					// left
					if (tl == 0) {
						for (int i = r - 1; i > indl; i--) {
							if (ind[i] < ind[l]) {
								tmp.push_back({i, l});
								l = i, tl = 1;
								break;
							}
						}
					} else {
						for (int i = l + 1; i < indr; i++) {
							if (ind[i] < ind[r]) {
								tmp.push_back({i, l});
								l = i, tl = 0;
								break;
							}
						}
					}
				} else {
					// right
					if (tr == 0) {
						for (int i = r - 1; i > indl; i--) {
							if (ind[i] > ind[r]) {
								tmp.push_back({r, i});
								r = i, tr = 1;
								break;
							}
						}
					} else {
						for (int i = l + 1; i < indr; i++) {
							if (ind[i] > ind[r]) {
								tmp.push_back({r, i});
								r = i, tr = 0;
								break;
							}
						}
					}
				}
				_s /= 2;
			}

			bool isok = 1;
			for (int i = 1; i < indl; i++) {
				if (x[i] == '1') {
					isok = 0;
				}
			}
			for (int i = indr + 1; i <= n; i++) {
				if (x[i] == '1') {
					isok = 0;
				}
			}

			if (isok) {
				for (auto [l, r] : op) {
					tmp.push_back({l, r});
				} 

				std::cout << tmp.size() << '\n';
				for (auto [l, r] : tmp) {
					std::cout << l << " " << r << '\n';
				}

				return;
			}
		}
	} else {
		for (int s = 0; s < 32; s++) {
			int _s = s;
			int indl = std::min(ind[1], ind[n]), indr = std::max(ind[1], ind[n]);
			int tl = 1, tr = 0;
			int l = n, r = 1;
			if (ind[1] < ind[n]) {
				tl = 0, tr = 1;
				l = 1, r = n;
			}

			std::vector<std::pair<int, int>> tmp;

			for (int round = 1; round <= 5; round++) {
				if (_s % 2) {
					// left
					if (tl == 0) {
						for (int i = r - 1; i > indl; i--) {
							if (ind[i] < ind[l]) {
								tmp.push_back({i, l});
								l = i, tl = 1;
								break;
							}
						}
					} else {
						for (int i = l + 1; i < indr; i++) {
							if (ind[i] < ind[r]) {
								tmp.push_back({i, l});
								l = i, tl = 0;
								break;
							}
						}
					}
				} else {
					// right
					if (tr == 0) {
						for (int i = r - 1; i > indl; i--) {
							if (ind[i] > ind[r]) {
								tmp.push_back({r, i});
								r = i, tr = 1;
								break;
							}
						}
					} else {
						for (int i = l + 1; i < indr; i++) {
							if (ind[i] > ind[r]) {
								tmp.push_back({r, i});
								r = i, tr = 0;
								break;
							}
						}
					}
				}
				_s /= 2;
			}

			bool isok = 1;
			for (int i = 1; i < l; i++) {
				if (x[i] == '1') {
					isok = 0;
				}
			}
			for (int i = r + 1; i <= n; i++) {
				if (x[i] == '1') {
					isok = 0;
				}
			}

			if (isok) {
				std::cout << tmp.size() << '\n';
				for (auto [l, r] : tmp) {
					std::cout << l << " " << r << '\n';
				}

				return;
			}
		}
	}
	std::cout << -1 << '\n';
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