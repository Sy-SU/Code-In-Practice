#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n;
	std::cin >> n;

	i64 _n = n;

	std::map<i64, int> fact;
	for (i64 s = 2; s * s <= n; s++) {
		while (n % s == 0) {
			fact[s]++, n /= s;
		}
	}
	if (n > 1) {
		fact[n]++;
	}

	int maxp = 0;
	i64 base = -1;
	for (auto [b, p] : fact) {
		if (p > maxp) {
			maxp = p, base = b;
		}
	}

	i64 mul = 1;
	for (int i = 1; i <= maxp; i++) {
		mul *= base;
	}

	i64 del = _n / mul;

	std::cout << maxp << '\n';
	for (int i = 1; i <= maxp; i++) {
		std::cout << (i == maxp ? base * del : base) << " \n"[i == maxp];
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