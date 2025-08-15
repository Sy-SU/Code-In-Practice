#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3000 + 10;
constexpr int mod = 998244353;

i64 a[N];
i64 Sparse_Table_f_max[N][30], Sparse_Table_f_min[N][30];

void init(i64 st[], int n)
{
	// 初始化 ST 表
	for (int i = 1; i <= n; i++)
	{
		Sparse_Table_f_max[i][0] = Sparse_Table_f_min[i][0] = st[i];
	}
	for (int j = 1; j <= log(n) / log(2); j++)
	{

		for (int i = 1; i <= n - (1 << j) + 1; i++)
		{ // 维护静态区间最大值
			Sparse_Table_f_max[i][j] = std::max(Sparse_Table_f_max[i][j - 1], Sparse_Table_f_max[i + (1 << (j - 1))][j - 1]);
			Sparse_Table_f_min[i][j] = std::min(Sparse_Table_f_min[i][j - 1], Sparse_Table_f_min[i + (1 << (j - 1))][j - 1]);
		}
	}
}

i64 queryMax(int l, int r)
{
	// 查询区间最大值
	int x = log(r - l + 1) / log(2);
	return std::max(Sparse_Table_f_max[l][x], Sparse_Table_f_max[r - (1 << x) + 1][x]);
}

i64 queryMin(int l, int r)
{
	// 查询区间最小值
	int x = log(r - l + 1) / log(2);
	return std::min(Sparse_Table_f_min[l][x], Sparse_Table_f_min[r - (1 << x) + 1][x]);
}

i64 pw[10000];

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

i64 C(i64 n, i64 m) {
	if (n < m) {
		return 0;
	}
	return pw[n] * inv(pw[m], mod) % mod * inv(pw[n - m], mod) % mod;
}

void solve() {
	int n, k;
	std::cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	init(a, n);

	if (k == 1) {
		std::cout << queryMax(1, n) * queryMin(1, n) % mod << '\n';
		return;
	}

	if (k == 2) {
		i64 ans = 0;
		for (int k = 1; k < n; k++) {
			ans = (ans + queryMax(1, k) * queryMin(1, k) % mod + queryMax(k + 1, n) * queryMin(k + 1, n) % mod) % mod;
		}
		std::cout << ans << '\n';
		return;
	}

	i64 ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			i64 add = queryMax(l, r) * queryMin(l, r) % mod;
			if (l == 1 && r == n) {
				continue;
			} else if (l == 1 && r != n) {
				ans = (ans + add * C(n - r - 1, k - 2)) % mod;
			} else if (l != 1 && r == n) {
				ans = (ans + add * C(l - 2, k - 2)) % mod;
			} else {
				ans = (ans + add * C(n + l - r - 3, k - 3)) % mod;
			}
		}
	}

	std::cout << ans << '\n';

}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	pw[0] = 1;
	for (int i = 1; i <= 8000; i++) {
		pw[i] = pw[i - 1] * i % mod;
	}

	solve();

	return 0;
}