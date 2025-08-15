#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;
	i64 x;
	std::cin >> x;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}

	i64 blk = (x - 1) / sum;
	if (blk >= k) {
		std::cout << 0 << '\n';
		return;
	}	

	// k - blk - 1 个完整的
	i64 add = blk * sum;
	// add + suf >= x
	i64 suf = 0;
	int pos = 1;
	for (int i = n; i >= 1; i--) {
		if (suf + add >= x) {
			pos = i + 1;
			break;
		}
		suf += a[i];
	}

	std::cout << (k - blk - 1) * n + pos << '\n';

	// i64 blk = x / sum;
	// if (blk > k) {
	// 	std::cout << 0 << '\n';
	// 	return;
	// }
	// i64 ans = blk * n;
	// x -= blk * sum;

	// i64 tmp = 0, los = n;
	// for (int i = n; i >= 1; i--) {
	// 	if (tmp >= x) {
	// 		los = n - i;
	// 		break;
	// 	}
	// 	tmp += a[i];
	// }

	// std::cout << n * k - ans - los + 1 << '\n';
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