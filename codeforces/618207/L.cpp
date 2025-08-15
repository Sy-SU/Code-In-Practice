#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

i64 qpow(i64 a, i64 b, i64 p)
{
	i64 res = 1;
	while (b)
	{
		if (b & 1)
			res = (res * a) % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

i64 inv(i64 x, i64 p)
{
	return qpow(x, p - 2, p);
}

void solve() {
	i64 n;
	std::cin >> n;

	if (n % 2) {
		n = (n + 1) / 2;
		std::cout << (inv(3, mod) * ((qpow(4, n, mod) - 4 + mod) % mod) % mod + 1) % mod << '\n';
	} else {
		n = n / 2;
		std::cout << 2 * (inv(3, mod) * ((qpow(4, n, mod) - 4 + mod) % mod) % mod + 1) % mod << '\n';
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