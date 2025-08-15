#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int mod = 1e9 + 7;

int n, q, k;

i64 a[N];
i64 arr[N];

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


std::vector<i64> merge(std::vector<i64> v1, std::vector<i64> v2) {
	std::vector<i64> res(k, 0);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			res[(i + j) % k] = (res[(i + j) % k] + v1[i] * v2[j] % mod) % mod;
		}
	}
	return res;
}

std::vector<i64> del(std::vector<i64> v1, std::vector<i64> v2) {
	std::vector<i64> res(k, 0);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			res[(i - j + k) % k] = (res[(i - j + k) % k] + v1[i] * v2[j] % mod) % mod;
		}
	}
	return res;
}

void solve() {
	std::cin >> n >> q >> k;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<i64>> pre(n + 1, std::vector<i64>(15, 0));
	for (int i = 1; i <= n; i++) {
		std::vector<i64> now(15, 0);
		now[0] = (a[i] - 1) * inv(a[i], mod) % mod;
		now[1] = inv(a[i], mod);

		if (i == 1) {
			pre[i] = now;
		} else {
			pre[i] = merge(pre[i - 1], now);
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j < k; j++) {
	// 		std::cerr << pre[i][j] << " \n"[j == k - 1];
	// 	}
	// }

	while (q--) {
		int l, r, p;
		std::cin >> l >> r >> p;
		if (l == 1) {
			std::cout << pre[r][p] << '\n';
		} else {
			std::cout << del(pre[r], pre[l - 1])[p] << '\n';
		}
		
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}