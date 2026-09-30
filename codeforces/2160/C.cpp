#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

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

	// int x;
	// std::cin >> x;
	// print(x ^ f(x));

	std::vector<int> v;
	while (n) {
		v.push_back(n % 2);
		n >>= 1;
	}
	std::reverse(v.begin(), v.end());

	while(!v.empty() && v.back() == 0) {
		v.pop_back();
	}

	int sz = v.size();
	for (int i = 0; i < sz; i++) {
		if (v[i] != v[sz - 1 - i]) {
			std::cout << "NO" << '\n';
			return;
		}
		if (i == sz - 1 - i) {
			if (v[i] == 1) {
				std::cout << "NO" << '\n';
				return;
			}
		}
	}
	std::cout << "YES" << '\n';
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