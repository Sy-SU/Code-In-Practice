#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 s, m;
	std::cin >> s >> m;

	std::vector<i64> base;
	i64 b = 1;
	while (m) {
		if (m % 2) {
			base.push_back(b);
		}
		m /= 2;
		b <<= 1;
	} 

	std::reverse(base.begin(), base.end());

	// for (auto bs : base) {
	// 	std::cerr << bs << " ";
	// }
	// std::cerr << '\n';

	i64 ans = -1;
	i64 lo = 1, hi = 1e18;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&](i64 max) -> bool {
			i64 num = s;
			for (auto bs : base) {
				i64 del = std::min(num / bs, max);
				num = num - del * bs;
				
				// std::cerr << max << " " << bs << " " << del << '\n';
			}
			if (num) {
				return 0;
			} else {
				return 1;
			}
		};

		if (check(mid)) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}

	std::cout << ans << '\n';
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