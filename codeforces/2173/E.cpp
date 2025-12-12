#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	std::vector<int> ind(n + 1);
	for (int i = 1; i <= n; i++) {
		ind[p[i]] = i;
	}
	
	// std::cerr << "ok\n";

	int cnt = 0;

	for (int now = 1; now <= n; now++) {
		// std::cerr << now << '\n';
		if (ind[now] == now) {
			continue;
		}
		int val1 = now;
		int ind1 = ind[val1];
		int val2 = p[val1];
		int ind2 = ind[val2];
		assert(ind1 != ind2);
		// std::cerr << val1 << " " << ind1 << " " << val2 << " " << ind2 << '\n';
		// swap(ind1, ind2)

		bool isp = ((n - ind1 + 1) == p[n - ind1 + 1]) | ((n - ind2 + 1) == p[n - ind2 + 1]);
		int cnt0 = 0, cnt1 = 0;
		while (1) {
			// std::cerr << "ask" << '\n';
			cnt++;
			int l = ind1, r = ind2;
			std::cout << "? " << l << " " << r << std::endl;
			int rl, rr;
			std::cin >> rl >> rr;

			int valpl = p[rl], valpr = p[rr];
			std::swap(p[rl], p[rr]);
			std::swap(ind[valpl], ind[valpr]);

			bool res = (rl == l) && (rr == r);
			// std::cerr << "res = " << res << '\n';
			if (res) {
				cnt1++;
			} else {
				cnt0++;
			}

			if (isp) {
				if (cnt0 % 2 == 0 && cnt1 % 2 == 1) {
					break;
				}
			} else {
				if (cnt1 % 2 == 1) {
					break;
				}
			}
		}
	}

	assert(cnt <= (800 + 2.5 * n));
	std::cout << "!" << std::endl;
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