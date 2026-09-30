#include <bits/stdc++.h>

using i64 = long long;

std::set<int> ok;

i64 f(i64 x) {
	i64 num = x;
	i64 res = 0;
	while (num) {
		res += num % 10;
		num /= 10;
	}
	return res;
}

void solve() {
	i64 x;
	std::cin >> x;

	int sum = 0;

	std::vector<int> v;
	while (x) {
		v.push_back(x % 10);
		sum += x % 10;
		x /= 10;
	}

	v.back()--;
	// std::cerr << sum << '\n';
	if (sum <= 9) {
		std::cout << 0 << '\n';
		return;
	}

	std::sort(v.begin(), v.end(), std::greater<int>());
	for (int i = 0; i < (int)v.size(); i++) {
		// std::cerr << "v = " << v[i] << '\n';
		if (sum - v[i] <= 9) {
			std::cout << i + 1 << '\n';
			return;
		}
		sum -= v[i];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for (int i = 1; i <= 200; i++) {
		if (i == f(i)) {
			ok.insert(i);
			// std::cerr << i << '\n';
		}
	}

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}