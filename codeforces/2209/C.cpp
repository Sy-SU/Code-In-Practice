#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	auto ask = [&](int i, int j) -> int {
		int res;
		std::cout << "? " << i << " " << j << std::endl;
		std::cin >> res;

		return res;
	};

	if (ask(1, 2) == 1) {
		std::cout << "! " << 1 << std::endl;
		return;
	}
	if (ask(1, 3) == 1) {
		std::cout << "! " << 1 << std::endl;
		return;
	}
	if (ask(2, 3) == 1) {
		std::cout << "! " << 2 << std::endl;
		return;
	}

	for (int i = 4; i <= 2 * n - 2; i += 2) {
		if (ask(i, i + 1) == 1) {
			std::cout << "! " << i << std::endl;
			return;
		}
	}
	std::cout << "! " << 2 * n << std::endl;
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