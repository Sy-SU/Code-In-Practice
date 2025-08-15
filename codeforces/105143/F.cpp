#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;
	k = n * n + 1 - k;

	auto query = [&](int i, int j, int x, int &res) -> void {
		std::cout << "? " << i << " " << j << " " << x << std::endl;
		std::cin >> res;
	};

	auto answer = [&](int ans) -> void {
		std::cout << "! " << ans << std::endl;
	};

	int lo = 1, hi = n * n;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		auto check = [&]() -> bool {
			// 2500 次操作
			// 每次二分一个 mid(是不是第 k 大？)
			// 小于等于 mid 的数有多少个？
			// cnt 表示 小于等于 mid 的个数
			int cnt = 0;

			int nowj = n;
			for (int i = 1; i <= n; i++) {
				int res = -1;

				while (1) {
					if (nowj < 1) {
						break;
					}
					query(i, nowj, mid, res);

					if (res) {
						break;
					}
					nowj--;
				}
				cnt += nowj;
			}
			std::cerr << cnt << '\n';
			return cnt >= k;
		};
/*
1 1 1 1 1 1 1 1 
1 2 3 4 6 8 8 9
1 3 3 5 6 9 9 9
1 5 6 6 6 9 9 9 
1 8 8 8 8 9 9 9

1 1 1 1 1 1 1 1
1 1 1 1 0 0 0 0
1 1 1 0 0 0 0 0
1 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0
*/
		if (check()) {
			hi = mid - 1;
			ans = mid;
		} else {
			lo = mid + 1;
		}
	}
	answer(ans);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}