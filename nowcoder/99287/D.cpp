#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e6 + 10;

std::vector<i64> ans(N + 1, 0);

void solve() {
	i64 m;
	std::cin >> m;

	int lo = 1, hi = 3107232;
	int x = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (ans[mid] <= m) {
			lo = mid + 1;
			x = mid;
		} else {
			hi = mid - 1;
		}
	}
	std::cout << x << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// 1 * 5 + 2 * 4 + 3 * 3 + 4 * 2 + 5 * 1
	// 1 * 4 + 2 * 3 + 3 * 2 + 4 * 1
	// 1 * 1 + 2 * 1 + 3 * 1 + 4 * 1 + 5 * 1

	i64 sum = 0;
	for (int mex = 1; mex <= 3107232; mex++) {
		ans[mex] = sum;
		sum += (mex + 1) * 1ll * mex / 2;
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}