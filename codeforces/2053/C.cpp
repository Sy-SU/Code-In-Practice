#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n, k;
	std::cin >> n >> k;

	i64 cnt = 0;
	i64 mul = 1;
	i64 l = 1, r = n;
	while (r - l + 1 >= k) {
		if (l % 2 == r % 2) {
			cnt += mul;
			r = (l + r) / 2 - 1;
		} else {
			r = (l + r) / 2;
		}
		mul *= 2;
	}
	std::cout << cnt * (1 + n) / 2 << '\n';

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