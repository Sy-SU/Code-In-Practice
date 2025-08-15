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

		i64 tmp = 0, dp = 0, p = b[i] * inv(100, mod) % mod;
		for (int j = 1; j <= now; j++) {
			dp = (j == 1 ? inv(p, mod) : (inv(p, mod) + (1 - p + mod) * inv(p, mod) % mod * dp % mod));
			dp %= mod;

			tmp = (tmp + dp) % mod;
		}

		ans = (ans + tmp) % mod;
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