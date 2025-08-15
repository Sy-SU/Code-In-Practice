#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e5 + 10;

constexpr int mod = 1e9 + 7;

using i128 = __int128_t;

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

i64 a[N], b[N];

i64 suf0[35][N], suf1[35][N], sufok[35][N];
i64 sufa0[35][N], sufa1[35][N], sufsufok[35][N];

i64 q2[35];

void solve() {
	int n, q;
	std::cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	for (int bi = 0; bi <= 30; bi++) {
		suf0[bi][n + 1] = suf1[bi][n + 1] = sufok[bi][n + 1] = sufa0[bi][n + 1] = sufa1[bi][n + 1] = sufsufok[bi][n + 1] = 0;
	}

	for (int i = n; i >= 1; i--) {
		for (int bi = 0; bi <= 30; bi++) {
			int tb = (b[i] >> bi) & 1;

			suf0[bi][i] = suf0[bi][i + 1] + (tb == 0);
			suf1[bi][i] = suf1[bi][i + 1] + (tb == 1);

			int ta = (a[i] >> bi) & 1;

			sufa0[bi][i] = sufa0[bi][i + 1] + (ta == 0);
			sufa1[bi][i] = sufa1[bi][i + 1] + (ta == 1);

			sufok[bi][i] = (((a[i] >> bi) & 1) ? suf0[bi][i] : suf1[bi][i]);
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int bi = 0; bi <= 30; bi++) {
			sufsufok[bi][i] = sufsufok[bi][i + 1] + sufok[bi][i];
		}
	}

	while (q--) {
		int l, r;
		std::cin >> l >> r;

		i64 ans = 0;
		for (int bi = 0; bi <= 30; bi++) {
			i64 tmp = sufsufok[bi][l] - sufsufok[bi][r + 1] - (sufa0[bi][l] - sufa0[bi][r + 1]) * suf1[bi][r + 1] - (sufa1[bi][l] - sufa1[bi][r + 1]) * suf0[bi][r + 1];
			assert(tmp >= 0);
			ans = (ans + q2[bi] * tmp % mod) % mod;
		}
		assert(ans >= 0 && ans < mod);
		std::cout << ans << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for (int i = 0; i <= 30; i++) {
		q2[i] = qpow(2, i, mod);
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}