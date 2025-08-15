#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
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

	std::string str;
	std::cin >> str;

	int num = 0;
	for (int i = 0; i < n; i++) {
		num += str[i] == '?';
	}

	if (n == 1) {
		std::cout << qpow(2, num, mod) << '\n';
		return;
	}

	i64 ans = 0;
	if ((str[0] == '1' && str[n - 1] == '0') || (str[0] == '0' && str[n - 1] == '1')) {
		ans = 2 * qpow(2, num, mod) % mod;
	} else if ((str[0] == '1' && str[n - 1] == '1') || (str[0] == '0' && str[n - 1] == '0')) {
		ans = (n - 2) * qpow(2, num, mod) % mod;
	} else {
		ans = n * qpow(2, num - 1, mod) % mod;
	}
	std::cout << ans << '\n';
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