#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m, a, b;
	std::cin >> n >> m >> a >> b;

	int _n = n, _m = m;

	_n = std::min(a, n - a + 1);

	int tans1 = 1;
	while (_n > 1) {
		_n = (_n + 1) / 2;
		tans1++;
	}
	while (_m > 1) {
		_m = (_m + 1) / 2;
		tans1++;
	}

	_n = n, _m = std::min(b, m - b + 1);

	int tans2 = 1;
	while (_n > 1) {
		_n = (_n + 1) / 2;
		tans2++;
	}
	while (_m > 1) {
		_m = (_m + 1) / 2;
		tans2++;
	}

	std::cout << std::min(tans1, tans2) << '\n';
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