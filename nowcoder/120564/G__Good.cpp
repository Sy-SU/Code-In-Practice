#include <bits/stdc++.h>

using i64 = long long;

i64 f(i64 x) {
	i64 res = 1;
	if (x == 0) {
		return 0;
	}
	while (x) {
		res *= (x % 10);
		x /= 10;
	}
	return res;
}

i64 g(i64 x) {
	int cnt = 0;
	while (x != f(x)) {
		// std::cerr << x << "->" << f(x) << '\n';
		x = f(x);
		cnt++;
	}
	return cnt;
}

std::vector<i64> fact(i64 x) {
	std::vector<i64> r;
	for (int ft = 9; ft >= 2; ft--) {
		while (x % ft == 0) {
			r.push_back(ft);
			x /= ft;
		}
	}
	return r;
}

void solve() {
	i64 x;
	std::cin >> x;

	std::cout << g(x) << '\n';

	i64 max = 1e1;

	i64 mx = 0;
	for (i64 i = max; i >= 0; i--) {
		mx = std::max(mx, g(i));
	}

	std::cout << "max = " << mx << '\n';
	std::set<i64> s;
	for (i64 i = max; i >= 0; i--) {
		if (mx == g(i)) {
			std::cout << i << "->" << f(i) << '\n';
			s.insert(f(i));
		}
	}
	std::cout << s.size() << '\n';
	for (auto num : s) {
		std::cout << num << '\n';
	}

	// std::cout << g(x) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}