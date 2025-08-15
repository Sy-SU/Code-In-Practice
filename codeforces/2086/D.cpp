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

i64 inv(i64 x, i64 p)
{
	return qpow(x, p - 2, p);
}

void solve() {
	std::vector<int> cnt(27, 0);
	int sum = 0;
	for (int i = 1; i <= 26; i++) {
		int x;
		std::cin >> x;
		cnt[i] = x;

		sum += x;
	}

	i64 ans = 1;
	for (int i = 1; i <= sum / 2; i++) {
		ans = (ans * i) % mod;
	}
	for (int i = 1; i <= (sum + 1) / 2; i++) {
		ans = (ans * i) % mod;
	}

	for (int x = 1; x <= 26; x++) {
		i64 tp = 1;
		for (int i = 1; i <= cnt[x]; i++) {
			tp = (tp * i) % mod;
		}
		ans = (ans * inv(tp, mod)) % mod;
	}
	std::vector<std::vector<i64>> dp(30, std::vector<i64>(sum + 1, 0));

	dp[0][0] = 1;
	for (int i = 1; i <= 26; i++) {
		for (int j = 0; j <= sum; j++) {
			dp[i][j] = (dp[i - 1][j] + (j >= cnt[i] && cnt[i] ? dp[i - 1][j - cnt[i]] : 0)) % mod;
		}
	}

	ans = (ans * dp[26][sum / 2]) % mod;
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