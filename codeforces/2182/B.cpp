#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b;
	std::cin >> a >> b;

	auto work = [&] (int a, int b) -> int {
		int cnt = 0, need = 1;
		int ua = 0, ub = 0;
		int x = 1;

		while (1) {
			if (x) {
				ua += need;
			} else {
				ub += need;
			}
			x = 1 - x;
			need <<= 1;
			cnt++;
			if (a < ua || b < ub) {
				return cnt - 1;
			}
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