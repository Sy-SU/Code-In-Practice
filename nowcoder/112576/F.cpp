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
	int n;
	std::cin >> n;

	std::vector<int> b(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> b[i];
	}

	std::sort(b.begin() + 1, b.end(), std::greater<int>());

	i64 ans = 0;
	for (int i = 1; i <= 2 * n; i++) {
		int now = n - (i - 1) / 2;

		i64 tmp = 0, p = b[i] * inv(100, mod) % mod;
		
		i64 add = 0;

		if (b[i] == 50) {
			add = now * (now + 1) % mod;
		} else {
			i64 q = (1 - p + mod) % mod * inv(p, mod) % mod;

			i64 A = now * inv(2 * p - 1 + mod, mod) % mod;
			i64 B = (qpow(q, now, mod) - 1 + mod) % mod * inv(q - 1 + mod, mod) % mod;
			i64 C = (inv(p, mod) - inv(2 * p - 1 + mod, mod) + mod) % mod;

			add = (A + B * C % mod) % mod;
		}
		ans = (ans + add) % mod;
		// std::cerr << ans << '\n';
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}