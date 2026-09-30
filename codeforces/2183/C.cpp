#include <bits/stdc++.h>

using i64 = long long;

struct Node {
	int len, rest;
};

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	auto work = [&](int n, int m, int k) -> int {
		int res = 0;
		for (int L = 1; L <= k; L++) {
			// k -> L
			// k - L
			int needt = std::max(0, 2 * (k - L) - 1);
			int base = needt + 1 - (k - L);
			if (needt > m) {
				continue;
			}
			int resm = m - needt;
			int x = std::max(0, (resm - base) / 2);
			int R = k + std::min(base + x, resm - x);
			R = std::min(R, n);
			res = std::max(res, R - L + 1);
		}
		return res;
	};

	std::cout << std::max(work(n, m, k), work(n, m, n + 1 - k)) << '\n';
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