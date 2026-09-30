#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	// int n;
	// std::cin >> n;

	auto f = [&](int x) -> int {
		std::vector<int> v;
		while (x) {
			v.push_back(x % 2);
			x >>= 1;
		}
		std::reverse(v.begin(), v.end());
		int r = 0, b = 1;
		for (auto y : v) {
			r += y * b, b <<= 1;
		}		
		return r;
	};

	// int x; std::cin >> x;
	// std::cerr << (x ^ f(x)) << '\n';

	auto print = [&](int x) -> void {
		std::vector<int> v;
		while (x) {
			v.push_back(x % 2);
			x >>= 1;
		}
		std::reverse(v.begin(), v.end());
		for (auto y : v) {
			std::cerr << y;
		}
		std::cerr << '\n';
	};

	std::map<int, int> ok;
	for (int x = 1; x <= 100000; x++) {
		ok[x ^ f(x)] = 1;
	}

	int n;
	std::cin >> n;

	std::cout << (ok[n] ? "YES" : "NO") << '\n';
 
	// int x;
	// std::cin >> x;
	// print(x ^ f(x));
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