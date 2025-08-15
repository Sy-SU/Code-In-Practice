#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

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

	std::string str;
	std::cin >> str;

	int len = str.size();

	n = n % (mod - 1) * len % (mod - 1);

	std::cout << (qpow(2, n, mod) - 1 + mod) % mod << '\n';
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