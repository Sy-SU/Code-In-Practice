#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int pos = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) {
			pos = i;
			break;
		}
	}

	std::vector<std::pair<int, int>> op;

	auto work = [&](int i, int j) -> void {
		op.push_back({i, j});
		a[i] += a[j];
	};

	auto check = [&]() -> bool {
		for (int i = 1; i <= n; i++) {
			std::cerr << a[i] << " \n"[i == n];
		}
		for (int i = 2; i <= n; i++) {
			if (a[i - 1] > a[i]) {
				return 0;
			}
		}
		return 1;
	};

	int poscnt = 0, negcnt = 0;
	int maxpos = 0, minneg = 0;
	int maxposind = -1, minnegind = -1;

	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) {
			poscnt++;
			if (a[i] > maxpos) {
				maxpos = a[i], maxposind = i;
			}
		} else if (a[i] < 0) {
			negcnt++;
			if (a[i] < minneg) {
				minneg = a[i], minnegind = i;
			}
		}
	}

	if (maxpos > -minneg) {
		if (negcnt <= 12) {
			// 让最大的正数加到所有负数上面去，序列变成全正数
			for (int i = 1; i <= n; i++) {
				if (a[i] < 0) {
					work(i, maxposind);
				}
			}

			for (int i = 2; i <= n; i++) {
				work(i, i - 1);
			}
		} else {
			// 随便挑一个负数出来操作 5 次，然后把正数都变成负数
			int sp = -1;
			for (int i = 1; i <= n; i++) {
				if (a[i] < 0) {
					work(i, i);
					work(i, i);
					work(i, i);
					work(i, i);
					work(i, i);
					sp = i;
					break;
				}
			}

			for (int i = 1; i <= n; i++) {
				if (a[i] > 0) {
					work(i, sp);
				}
			}

			for (int i = n - 1; i >= 1; i--) {
				work(i, i + 1);
			}
		}
	} else {
		if (poscnt <= 12) {
			for (int i = 1; i <= n; i++) {
				if (a[i] > 0) {
					work(i, minnegind);
				}
			}

			for (int i = n - 1; i >= 1; i--) {
				work(i, i + 1);
			}
		} else {
			int sp = -1;
			for (int i = 1; i <= n; i++) {
				if (a[i] > 0) {
					work(i, i);
					work(i, i);
					work(i, i);
					work(i, i);
					work(i, i);
					sp = i;
					break;
				}
			}

			for (int i = 1; i <= n; i++) {
				if (a[i] < 0) {
					work(i, sp);
				}
			}

			for (int i = 2; i <= n; i++) {
				work(i, i - 1);
			}
		}
	}

	std::cout << op.size() << '\n';
	for (auto [x, y] : op) {
		std::cout << x << " " << y << '\n';
	}

	if (!check()) {
		std::cerr << "Failed" << '\n';
		exit(-1);
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