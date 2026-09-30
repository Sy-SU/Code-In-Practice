#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}

	i64 cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cnt += a[i][j];
		}
	}

	std::vector<int> cntr(m + 1);
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			cntr[j] += a[i][j];
		}
	}

	std::cout << cnt / 2 * (cnt - cnt / 2) << '\n';

	int left = 0, p = m;
	std::string op;
	for (int j = 1; j <= m; j++) {
		if (left + cntr[j] <= cnt / 2) {
			left += cntr[j];
			op += "R";
		} else {
			int need = cntr[j] - (cnt / 2 - left);
			// std::cerr << "j = " << j <<  "need = " << need << '\n';
			for (int i = 1; i <= n; i++) {
				// a[i][j]
				if (a[i][j] && need > 0) {
					need--;
				}
				op += "D";
				if (need == 0) {
					op += "R";
					need--;
				}
			}
			p = j;
			break;
		}
	}

	for (int i = 1; i <= m - p; i++) {
		op += "R";
	}
	if (op.size() < n + m) {
		int sz = op.size();
		for (int i = 1; i <= n + m - sz; i++) {
			op += "D";
		}
	}

	int cntR = 0, cntD = 0;
	for (auto ch : op) {
		if (ch == 'R')cntR++;
		else cntD++;
	}
	assert(cntR == m && cntD == n);
	std::cout << op << '\n';
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