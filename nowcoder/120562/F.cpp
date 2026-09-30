#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	std::cin >> n;

	int bit = 0;
	auto _n = n;

	while (_n) {
		bit++;
		_n /= 2;
	}

	i64 mul = (1ll << bit);

	i64 x = mul * n, y = (mul + 1) * n;

	std::cout << x << " " << y << '\n';
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