#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int l, r;
	std::cin >> l >> r;

	if (l % 2 == r % 2) {
		int n = r - l + 1;
		int A = n / 2 + 1, B = n / 2;

		if (l % 2 == 1) {
			// A 奇 B 偶
			std::cout << "Alice" << '\n';
		} else {
			// A 偶 B 奇
			if (r >= (l + 1) * 2) {
				std::cout << "Bob" << '\n';
			} else {
				std::cout << "Alice" << '\n';
			}
		}

	} else {
		int n = r - l + 1;
		int A = n / 2, B = n / 2;

		if (l % 2 == 1) {
			// A 奇 B 偶
			if (r >= l * 2) {
				std::cout << "Alice" << '\n';
			} else {
				std::cout << "Bob" << '\n';
			}
		} else {
			// A 偶 B 奇
			std::cout << "Bob" << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}