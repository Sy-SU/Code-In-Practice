#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	auto check = [&](int num) -> bool {
		while (num) {
			if (num % 10 == 7) {
				return 1;
			}
			num /= 10;
		}
		return 0;
	};

	for (int i = 0; i <= 7; i++) {
		int num = n - i;
		// std::cerr << num << '\n';
		while (num) {
			if (num % 10 <= 7) {
				if (num % 10 + i >= 7) {
					std::cout << i << '\n';
					return;
				} 
			}else {
				if (num % 10 + i >= 17) {
					std::cout << i << "\n";
					return;
				}
			}
			num /= 10;
		}
	}
	std::cout << 7 << '\n';
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