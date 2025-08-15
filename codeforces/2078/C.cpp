#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> b[i];
	}

	std::sort(b.begin() + 1, b.end(), std::greater<int>());

	if (n == 1) {
		std::cout << b[1] << " " << b[1] + b[2] << " " << b[2] << '\n';
		return;
	}

	i64 sum = 0;
	for (int i = 1; i <= 2 * n; i++) {
		sum += b[i] * (i <= n ? 1 : -1);
	}

	if (sum > b[1]) {
		std::cout << sum << " ";
		for (int i = 1; i <= n; i++) {
			std::cout << b[i] << " " << b[n + i] << " \n"[i == n];
		}
	} else if (sum < b[1]) {
		std::cout << b[1] << " " << b[1] - (sum - b[1]) << " ";
		for (int i = 1; i <= n; i++) {
			if (i != 1) {
				std::cout << b[i] << " " << b[n + i] << " \n"[i == n];
			} else {
				std::cout << b[n + i] << " \n"[i == n];
			}	
		}
	} else {
		std::swap(b[n], b[n + 1]);
		sum = 0;
		for (int i = 1; i <= 2 * n; i++) {
			sum += b[i] * (i <= n ? 1 : -1);
		}
		assert(sum != 0);
		if (sum > b[1]) {
		std::cout << sum << " ";
			for (int i = 1; i <= n; i++) {
				std::cout << b[i] << " " << b[n + i] << " \n"[i == n];
			}
		} else if (sum < b[1]) {
			std::cout << b[1] << " " << b[1] - (sum - b[1]) << " ";
			for (int i = 1; i <= n; i++) {
				if (i != 1) {
					std::cout << b[i] << " " << b[n + i] << " \n"[i == n];
				} else {
					std::cout << b[n + i] << " \n"[i == n];
				}	
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