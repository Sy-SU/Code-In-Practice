#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b;
	std::cin >> a >> b;

	auto work = [&](int a, int b) -> int {
		int base = 1; // 当前层需要的数量
		int cnt = 0; // 做好的层数
		int now = 1; // 1 -> a 0 -> b
		int cnta = 0, cntb = 0;

		while (1) {
			if (now) {
				// 使用 a
				cnta += base;
			} else {
				// 使用 b
				cntb += base;
			}
			if (cnta > a || cntb > b) {
				return cnt;
			}
			base <<= 1;
			cnt++;
			now = 1 - now; // 交换使用的巧克力
		}
	};

	std::cout << std::max(work(a, b), work(b, a)) << '\n';
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