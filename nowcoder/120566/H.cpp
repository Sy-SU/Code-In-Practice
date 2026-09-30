#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> ok(2048);
	ok[0] = 1;
	for (int i = 1; i <= n; i++) {
		std::vector<int> tmp(2048);
		for (int j = 0; j < 2048; j++) {
			if (ok[j]) {
				tmp[std::max(0, j - a[i])] = 1;
				tmp[b[i] ^ j] = 1;
			}
		}
		ok = tmp;
	}
	for (int i = 2047; i >= 0; i--) {
		if (ok[i]) {
			std::cout << i << '\n';
			return;
		}
	}
} 

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}