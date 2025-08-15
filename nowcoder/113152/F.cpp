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

	// 3 * 3 + 23 * 23

	// a_n = 2 * (10^n - 1) / 9 + 1 = 2 * 10^n / 9 + 7 / 9 
	// a_n * a_n = 4 * 100^n /81 + 28 * 10^n / 81 + 49 / 81

	i64 ans = 49 * (n % mod) % mod * inv(81, mod) % mod;
	i64 add1 = 4 * inv(81, mod) % mod * 100 % mod * (qpow(100, n, mod) - 1 + mod) % mod * inv(99, mod) % mod;
	i64 add2 = 28 * inv(81, mod) % mod * 10 % mod * (qpow(10, n, mod) - 1 + mod) % mod * inv(9, mod) % mod;
	assert(ans >= 0 && ans < mod);
	assert(add1 >= 0 && add1 < mod);
	assert(add2 >= 0 && add2 < mod);
	std::cout << (ans + add1 + add2) % mod << '\n';

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}