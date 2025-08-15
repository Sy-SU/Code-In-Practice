#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

#define int long long

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
	i64 n, m, k;
	std::cin >> n >> m >> k;

	assert(n * m >= k);

	i64 cnt = 0, cntBlack = 0; // 贴着墙的
	for (int i = 1; i <= k; i++) {
		i64 x, y, c;
		std::cin >> x >> y >> c;
		if (x == 1 || x == n) {
			if (y > 1 && y < m) {
				cnt++;
				cntBlack += c;
			}
		}
		if (y == 1 || y == m) {
			if (x > 1 && x < n) {
				cnt++;
				cntBlack += c;
			}
		}
	}

	// i64 space = n * m - 2 * (n - 2) - 2 * (m - 2);
	// space -= (k - cnt);
	i64 spaceWall = 2 * (n - 2) + 2 * (m - 2) - cnt;
	assert(spaceWall >= 0);

	if (spaceWall == 0) {
		if (cntBlack % 2 == 0) {
			std::cout << qpow(2, (n * m - k) % mod, mod) << '\n';
			assert(qpow(2, (n * m - k) % mod, mod) >= 0 && qpow(2, (n * m - k) % mod, mod) < mod);
		} else {
			std::cout << 0 << '\n';
		}
		return;
	}

	// 2 ^ (space + spaceWall - 1)
	assert(qpow(2, (n * m - k - 1) % mod, mod) >= 0 && qpow(2, (n * m - k - 1) % mod, mod) < mod);
	std::cerr << (n * m - k - 1) % mod << " " << qpow(2, (n * m - k - 1) % mod, mod) << '\n';
	std::cout << qpow(2, (n * m - k - 1) % mod, mod) << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}