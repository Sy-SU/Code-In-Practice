#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::pair<int, int>> seg(m + 1);
	for (int i = 1; i <= m; i++) {
		int l, r;
		std::cin >> l >> r;

		seg[i] = {l, r};
	}

	std::sort(seg.begin() + 1, seg.end());

	std::vector<int> col(2 * n + 1);
	int lst = 1e9, cnt = 0;
	for (int i = m; i >= 1; i--) {
		auto [l, r] = seg[i];
		if (r >= lst) {
			continue;
		} else {
			col[l] = 1;
			lst = l;
			cnt++;
		}
	}

	if (cnt > n) {
		std::cout << -1 << '\n';
		return;
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (cnt >= n) {
			continue;
		}
		if (col[i]) {
			continue;
		}
		col[i] = 1, cnt++;
	}

	int cnt1 = 0;
	for (int i = 1; i <= 2 * n; i++) {
		cnt1 += col[i] == 1;
		if (cnt1 < i - cnt1) {
			std::cout << -1 << '\n';
			return;
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		std::cout << (col[i] ? '(' : ')');
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