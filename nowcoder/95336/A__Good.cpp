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

int n;

i64 l[N], r[N];

i64 arr[N];

i64 ans = 0;

int aaa;

void dfs(int pos) {
	if (pos == n + 1) {
		return;
	}

	for (int i = l[pos]; i <= r[pos]; i++) {
		arr[pos] = i;
		if (pos == n) {
			for (int i = 2; i <= n; i++) {
				ans += std::abs(arr[i] - arr[i - 1]);
			} 
			aaa++;
		}
		dfs(pos + 1);
	}
}

void solve() {
	std::cin >> n;

	i64 possi = 1;
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i] >> r[i];
		possi = possi * (r[i] - l[i] + 1) % mod;
	}

	dfs(1);

	std::cout << ans * inv(possi, mod) % mod << '\n';
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