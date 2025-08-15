#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;

i64 pw[N], invpw[N];

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
	// std::cerr << n << " " << m << '\n';
	i64 res = pw[n] * invpw[n - m] % mod * invpw[m] % mod;
	return res;
}


void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string str;
	std::cin >> str;

	str = "1" + str + "1";

	int ans = 0;

	std::vector<int> pos1;
	for (int i = 0; i <= n + 1; i++) {
		if (str[i] == '1') {
			pos1.push_back(i);
		}
	}

	int sz = pos1.size();

	if (sz <= k + 1) {
		std::cout << 0 << '\n';
		return;
	}

	{
		int r = k + 1;
		int l = r - k - 1;
		int lo = pos1[l] + 1, hi = pos1[r] - 1;
		// std::cerr << lo << " " << hi << '\n';

		ans = (ans + C(hi - lo + 1, k)) % mod;
	}

	for (int r = k + 1; r < sz - 1; r++) {
		int l = r - k;
		int lo = pos1[l] + 1, hi = pos1[r] - 1;

		ans = (ans + C(hi - lo + 1, k)) % mod;
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	pw[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		pw[i] = pw[i - 1] * i % mod;
	}
	for (int i = 0; i <= 100000; i++) {
		invpw[i] = inv(pw[i], mod);
	}

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}