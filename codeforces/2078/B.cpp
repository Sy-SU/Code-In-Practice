#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	if (k % 2) {
		for (int i = 1; i <= n; i++) {
			std::cout << (i == n ? n - 1 : n) << " \n"[i == n];
		}
	} else {
		if (n == 2) {
			std::cout << "2 1" << '\n';
		} else {
			for (int i = 1; i <= n; i++) {
				std::cout << (i == n - 1 ? n : n - 1) << " \n"[i == n];
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