#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 a, b, c, m;
	std::cin >> a >> b >> c >> m;

	i64 ab = a * b / std::gcd(a, b);
	i64 ac = a * c / std::gcd(a, c);
	i64 bc = b * c / std::gcd(b, c);

	i64 abc = ab * c / std::gcd(ab, c);

	i64 cnta = m / a - m / ab - m / ac + m / abc;
	i64 cntb = m / b - m / bc - m / ab + m / abc;
	i64 cntc = m / c - m / ac - m / bc + m / abc;
	i64 cntab = m / ab - m / abc;
	i64 cntac = m / ac - m / abc;
	i64 cntbc = m / bc - m / abc;
	i64 cntabc = m / abc;

	i64 ansa = cnta * 6 + cntab * 3 + cntac * 3 + cntabc * 2;
	i64 ansb = cntb * 6 + cntab * 3 + cntbc * 3 + cntabc * 2;
	i64 ansc = cntc * 6 + cntac * 3 + cntbc * 3 + cntabc * 2;
	// std::cerr << cnta << " " << cntab << " " << cntac << " " << cntabc << '\n';
	std::cout << ansa << " " << ansb << " " << ansc << '\n';
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