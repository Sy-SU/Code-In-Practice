#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;

	std::vector<int> p(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	if (n == 2) {
		std::cout << "Alice" << '\n';
		return;
	}

	if (str == "Alice") {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += p[i] != i;
		}
		if (cnt == 2) {
			std::cout << "Alice" << '\n';
			return;
		}
		std::cout << "Bob" << '\n';
	} else {
		if (n >= 4) {
			std::cout << "Bob" << '\n';
			return;
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += p[i] != i;
		}
		if (n == 3) {
			if (cnt == 2) {
				std::cout << "Bob" << '\n';
				return;
			}
			std::cout << "Alice" << '\n';
			return;
		}
		std::cout << "Bob" << '\n';
		// 1 3 2 -> 3 1 2
		// 2 1 3 -> 2 3 1
		// 2 3 1 -> 2 1 3A
		//		 -> 3 2 1A
		// 3 1 2 -> 1 3 2A
		//       -> 3 2 1A
		// 3 2 1 -> 2 3 1
		//       -> 3 1 2
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