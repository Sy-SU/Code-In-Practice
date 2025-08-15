#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128_t;

void solve() {
	int n;
	i64 y, M;
	std::cin >> n >> y >> M;

	std::vector<std::vector<i64>> a(n + 1);
	std::vector<int> l(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i];
		a[i].resize(l[i] + 1);
		for (int j = 1; j <= l[i]; j++) {
			std::cin >> a[i][j];
		}
	}

	bool isINF = 0;
	i64 lef = y, rig = y;
	for (int ind = n; ind >= 1; ind--) {
		// target = Σ a[i] * x^(l[ind] - i)
		auto checkleft = [&](i64 x) -> bool {
			// f(x) >= l, min x
			i128 sum = 0, base = 1;
			for (int i = l[ind]; i >= 1; i--) {
				sum += base * a[ind][i];
				if (sum >= lef) {
					return 1;
				}
				base *= x;
				if (base >= 1e12) {
					return 1;
				}
			}

			return (sum >= lef);
		};

		auto checkright = [&](i64 x) -> bool {
			// f(x) <= r, max x
			i128 sum = 0, base = 1;
			for (int i = l[ind]; i >= 1; i--) {
				sum += base * a[ind][i];
				if (sum > rig) {
					return 0;
				}
				base *= x;
				if (base >= 1e12) {
					return 0;
				}
			}

			return (sum <= rig);
		};

		i64 lef_lo = *std::max_element(a[ind].begin() + 1, a[ind].end()) + 1, lef_hi = M;
		i64 candi_lef = 1e12;
		while (lef_lo <= lef_hi) {
			i64 lef_mid = (lef_lo + lef_hi) / 2;
			if (checkleft(lef_mid)) {
				lef_hi = lef_mid - 1;
				candi_lef = lef_mid;
			} else {
				lef_lo = lef_mid + 1;
			}
		}

		if (a[ind].size() == 2) {
			isINF = 1;
		}

		i64 rig_lo = *std::max_element(a[ind].begin() + 1, a[ind].end()) + 1, rig_hi = M;
		i64 candi_rig = -1;
		while (rig_lo <= rig_hi) {
			i64 rig_mid = (rig_lo + rig_hi) / 2;
			if (checkright(rig_mid)) {
				rig_lo = rig_mid + 1;
				candi_rig = rig_mid;
			} else {
				rig_hi = rig_mid - 1;
			}
		}

		if (isINF) {
			candi_rig = rig = M;
		}

		if (candi_rig < candi_lef) {
			std::cout << -1 << " " << -1 << '\n';
			return;
		}
		lef = candi_lef, rig = candi_rig;
		// std::cerr << lef << " " << rig << '\n';
	}
	
	std::cout << lef << " " << rig << '\n';

	auto checker = [&]() -> bool {
		bool isok = 1;
		for (int sta = 2; sta <= M; sta++) {
			i64 now = sta;
			bool pass = 1;
			for (int i = 1; i <= n; i++) {
				i64 to = 0, base = 1;
				for (int j = l[i]; j >= 1; j--) {
					if (a[i][j] >= now) {
						pass = 0;
					}
					to += a[i][j] * base;
					base *= now;
				}
				now = to;
			}

			if (now != y) {
				pass = 0;
			}
			if (pass == 0) {
				if (sta >= lef && sta <= rig) {
					isok = 0;
					std::cerr << "debug1 " << sta << '\n';
					system("pause");
				}
			} else {
				if (sta < lef || sta > rig) {
					isok = 0;

					std::cerr << "debug2 " << sta << '\n';
					system("pause");
				}
			}
		}
		return isok;
	};

	// assert(checker());
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