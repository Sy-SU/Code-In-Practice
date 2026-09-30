#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> ind;
	for (int i = 1; i < n; i++) {
		ind.push_back(i);
	}

	int qcnt = 0;

	int pre = 0, base = 0, ans = 0;
	while ((1 << base) <= n) {
		int q = pre + (1 << base);

		std::vector<int> odd, even;

		for (auto num : ind) {
			std::cout << "? " << num << " " << q << std::endl;qcnt++;assert(qcnt <= 2 * n);
			int res = 0;
			std::cin >> res;

			if (res == 0) {
				even.push_back(num);
			} else {
				odd.push_back(num);
			}
		}

		int cnt0 = even.size(), cnt1 = odd.size();

		// int sum = (n - ans) / (1 << base) + 1;
		int need0 = 0, need1 = 0;
		int now = ans;
		while (now <= n) {
			if (1 <= now) {
				int del = (now - ans) / (1 << base);
				if (del % 2) {
					need1++;
				} else {
					need0++;
				}
			}
			now += (1 << base);
		}

		// std::cerr << "cnt0 = " << cnt0 << "\n";
		// std::cerr << "cnt1 = " << cnt1 << '\n';
		// std::cerr << "need0 = " << need0 << '\n';
		// std::cerr << "need1 = " << need1 << '\n';

		if (need0 == cnt0 + 1) {
			assert(need1 == cnt1);
			// std::cerr << "even" << '\n';

			pre += (1 << base);
			ind = even;
		} else if (need1 == cnt1 + 1) {
			assert(need0 == cnt0);
			// std::cerr << "odd" << '\n';

			ans += (1 << base);
			ind = odd;
		} else {
			assert(0);
		}

		base++;
	}

	assert(ans >= 1 && ans <= n);
	std::cout << "! " << ans << std::endl;
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