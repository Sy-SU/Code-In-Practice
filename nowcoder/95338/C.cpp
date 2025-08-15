#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

i64 po(i64 a, int b) {
	i64 res = 1;
	for (int i = 1; i <= b; i++) {
		res *= a;
	}
	return res;
}

void solve() {
	i64 k;
	std::cin >> k;

	i64 lo = 1, hi = 2e18;
	i64 ans = -1;
	while (lo <= hi) {
		i64 mid = (lo + hi) / 2;

		auto check = [&]() -> bool {
			// 2 * k + cnt = ans
			i64 mlog = log2(2 * mid);
			if (po(2, mlog) > 2 * mid) {
				mlog--;
			}
			if (po(2, mlog + 1) <= 2 * mid) {
				mlog++;
			}
			i64 cnt = mlog;
			// if (cnt > 1 && po(2, cnt) == 2 * mid) {
			// 	mid++;
			// }
			return (mid - cnt + 1) >= k;
		};

		if (check()) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}	
	std::cout << 2 * ans << '\n';
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