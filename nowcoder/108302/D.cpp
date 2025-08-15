#include <bits/stdc++.h>

using i64 = long long;

int a[4] = {3, 1, 2, 0};

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	if (n >= 5) {
		int del = n / 4, res = n % 4;
		for (int i = 1; i <= del; i++) {
			for (int k = 0; k < 4; k++) {
				a[4 * (i - 1) + ]
			}
		}
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