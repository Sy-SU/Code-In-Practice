#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	i64 l, r;
	std::cin >> l >> r;

	auto calc = [&](i64 x) -> i64 {
		i64 sum1 = x / 2 + x / 3  + x / 5 + x / 7;
		i64 sum2 = x / 6 + x / 10 + x / 14 + x / 15 + x / 21 + x / 35;
		i64 sum3 = x / 105 + x / 70 + x / 42 + x / 30;
		i64 sum4 = x / 210;

		return sum1 - sum2 + sum3 - sum4;
	};

	l--;
	std::cout << (r - calc(r)) - (l - calc(l)) << '\n';
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