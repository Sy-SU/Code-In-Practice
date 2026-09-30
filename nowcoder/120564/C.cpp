#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a((1 << n) + 1);
	// for (int i = 0; i < (1 << n); i++) {
	// 	std::cin >> a[i];
	// }

	// int ans = 0;
	// for (int i = 1; i < (1 << n); i++) {
	// 	ans += (a[i - 1] ^ a[i]);
	// }
	// std::cout << ans << '\n';

	a[0] = 0, a[1] = 1;
	if (n > 1) {
		for (int s = 2; s <= n; s++) {
			int l = (1 << (s - 1)), r = (1 << s) - 1;
			for (int i = l; i <= r; i++) {
				a[i] = l + a[r - i];
			}
		}
	}

	for (int i = 0; i < (1 << n); i++) {
		std::cout << a[i] << " ";
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}