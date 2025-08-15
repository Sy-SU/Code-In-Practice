#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
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

i64 inv(i64 x, i64 p)
{
	return qpow(x, p - 2, p);
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 2, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0, bas = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			bas = (bas + 1) % mod;
		} else if (a[i] == 2) {
			bas = (bas * 2) % mod;
		} else {
			ans = (ans + bas) % mod;
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			cnt++;
		} else if (a[i] == 3) {
			ans = (ans - cnt + mod) % mod;
		}
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