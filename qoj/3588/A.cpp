#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	// x
	// 97 * x ~ 97 * x + 25 * x

	int x2 = (121 + n) / 122, x1 = n / 97;
	// x2 <= x <= x1

	if (x2 > x1) {
		std::cout << "No" << '\n';
		return;
	}

	std::cout << "Yes" << '\n';
	int len = x1, sum = len * 97;
	std::vector<int> ans(len);
	for (int i = 0; i < len; i++) {
		if (sum < n) {
			int add = std::min(n - sum, 25);
			sum += add, ans[i] = add;
		}
	}

	for (int i = 0; i < len; i++) {
		std::cout << (char)('a' + ans[i]);
	}
	std::cout << '\n';
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