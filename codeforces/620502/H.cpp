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

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::string a, b;
	std::cin >> a >> b;

	if (n >= m) {
		std::string add(n - m, '0');

		b = add + b;
	} else {
		std::string add(m - n, '0');
		
		a = add + a;
	}

	int sz = std::max(n, m);

	i64 ans = 0, cnt = 0;
	for (int i = 0; i < sz; i++) {
		cnt += b[i] == '1';
		if (a[i] == '1') {
			ans = (ans + cnt * qpow(2, sz - 1 - i, mod) % mod) % mod;
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}