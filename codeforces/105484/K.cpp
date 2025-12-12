#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, k, w;
	std::cin >> n >> m >> k >> w;

	std::vector<int> a(n + 1), b(m + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}

	b[m + 1] = w + 1;
	m++;

	std::sort(a.begin() + 1, a.end());
	std::sort(b.begin() + 1, b.end());

	int lst = 0;
	std::vector<int> op;
	for (int bi = 1; bi <= m; bi++) {
		int rbound = b[bi], lbound = b[bi - 1];

		int sta = lst + 1, end = sta - 1;
		for (int i = sta; i <= n && a[i] < rbound; i++) {
			end = i;
		}

		// std::cerr << sta << " " << end << '\n';

		// a[sta] ~ a[end]
		std::vector<int> tmp;
		int r = -1;
		for (int i = sta; i <= end; i++) {
			if (a[i] > r) {
				r = a[i] + k - 1;
				tmp.push_back(a[i]);
				// std::cerr << "tmp push" << a[i] << " " << r << '\n';
			}
		}

		while (!tmp.empty()) {
			int lo = tmp.back();
			tmp.pop_back();
			int hi = lo + k - 1;
			// std::cerr << "pop " << lo << " " << hi << '\n';

			if (hi >= rbound) {
				hi = rbound - 1, lo = hi - k + 1;
				if (lo <= lbound) {
					std::cout << -1 << '\n';
					return;
				}
				rbound = lo;
			}
			// std::cerr << "ans" << lo << " " << lo + k - 1 << '\n';
			op.push_back(lo);
		}

		lst = end;
	}

	std::cout << op.size() << '\n';
	for (auto o : op) {
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