#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 n;
	std::cin >> n;

	auto add = [&](i64 y) -> int {
		std::cout << "add" << " " << y << std::endl;
		int r;
		std::cin >> r;
		// res = (r ? res : res + y);
		return r;
	};

	auto mul = [&](i64 y) -> int {
		std::cout << "mul" << " " << y << std::endl;
		int r;
		std::cin >> r;
		// res = (r ? res : res * y);
		return r;
	};

	auto dv = [&](i64 y) -> int {
		std::cout << "div" << " " << y << std::endl;
		int r;
		std::cin >> r;
		// res = (r ? res : res / y);
		return r;
	};

	auto digit = [&]() -> void {
		std::cout << "digit" << std::endl;
		int r;
		std::cin >> r;
		// i64 tmp = 0;
		// while (res) {
		// 	tmp += res % 10;
		// 	res /= 10;
		// }
		// res = tmp;
	};

	mul(9), digit(), digit(), add(n - 9);
	std::cout << "!" << std::endl;

	int r;
	std::cin >> r;
	if (r != 1) {
		return;
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