#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	if (n % 2 == 0) {
		if (k % 2 == 1) {
			k--;
		}
		std::cout << (n + k - 1) / k << '\n';
	} else {
		if (k % 2 == 1) {
			n -= k;
			k--;
		} else {
			n -= (k - 1);
		}
		std::cout << 1 + (n + k - 1) / k << '\n';
	}
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