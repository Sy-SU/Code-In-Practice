#include <bits/stdc++.h>

using i64 = long long;

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
	i64 p, q, r;
	std::cin >> p >> q >> r;

	i64 pk = p * inv(1000, mod) % mod;

	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(3));
	dp[0][0] = 1;

	auto push_before = [&](i64 num, int i) -> void {
		if (num == 0) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2];
		} else if (num == 1) {
			dp[i][1] += dp[i - 1][0] * pk % mod + dp[i - 1][1] * (1 - pk + mod) % mod;
			dp[i][1] %= mod;

			dp[i][2] += dp[i - 1][1] * pk % mod + dp[i - 1][2] % mod;
			dp[i][2] %= mod;

			dp[i][0] += dp[i - 1][0] * (1 - pk + mod) % mod;
			dp[i][0] %= mod;
		} else {
			i64 p0 = qpow((1 - pk + mod) % mod, num, mod);
			i64 p1 = num * qpow((1 - pk + mod) % mod, num - 1, mod) % mod * pk % mod;
			i64 p2 = (1 - p0 - p1 + mod + mod) % mod;
			// std::cerr << p0 << " " << p1 << " " << p2 << '\n';

			dp[i][0] += dp[i - 1][0] * p0 % mod;
			dp[i][1] += (dp[i - 1][0] * p1 % mod + dp[i - 1][1] * p0 % mod) % mod;
			dp[i][2] += (dp[i - 1][0] * p2 % mod + dp[i - 1][1] * (p1 + p2) % mod + dp[i - 1][2]) % mod;
		}
		std::cerr << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';
	};

	auto push_after = [&](i64 num, int i) -> void {
		if (num == 0) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2];
		} else if (num == 1) {
			i64 pkk = (pk + (1 - pk + mod) * q % mod * inv(1000, mod) % mod) % mod;
			dp[i][1] += dp[i - 1][0] * pkk % mod + dp[i - 1][1] * (1 - pkk + mod) % mod;
			dp[i][1] %= mod;

			dp[i][2] += dp[i - 1][1] * pkk % mod + dp[i - 1][2] % mod;
			dp[i][2] %= mod;

			dp[i][0] += dp[i - 1][0] * (1 - pkk + mod) % mod;
			dp[i][0] %= mod;
		} else {
			i64 pkk = pk * (1000 - q) % mod * inv(1000, mod) % mod;
			i64 p0 = qpow((1 - pkk + mod) % mod, num, mod);
			i64 p1 = num * qpow((1 - pkk + mod) % mod, num - 1, mod) % mod * pkk % mod;
			i64 p2 = (1 - p0 - p1 + mod + mod) % mod;

			dp[i][0] += dp[i - 1][0] * p0 % mod;
			dp[i][1] += (dp[i - 1][0] * p1 % mod + dp[i - 1][1] * p0 % mod) % mod;
			dp[i][2] += (dp[i - 1][0] * p2 % mod + dp[i - 1][1] * (p1 + p2) % mod + dp[i - 1][2]) % mod;
		}
	};

	auto push_mid = [&](i64 prenum, i64 sufnum, int i) -> void {
		i64 pkk = (pk + (1 - pk + mod) * q % mod * inv(1000, mod) % mod) % mod;
		// prenum 个 pk, sufnum 个 pkk
		if (prenum == 0 && sufnum == 0) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2];
		} else if (sufnum == 0) {
			push_before(prenum, i);
		} else if (prenum == 0) {
			push_after(sufnum, i);
		} else {
			i64 p0 = qpow((1 - pk + mod) % mod, prenum, mod) * qpow((1 - pkk + mod), sufnum, mod) % mod;
			i64 p1 = (prenum * pk % mod * qpow((1 - pk + mod) % mod, prenum - 1, mod) % mod * qpow((1 - pkk + mod), sufnum, mod) % mod + sufnum * pkk % mod * qpow((1 - pk + mod) % mod, prenum, mod) % mod * qpow((1 - pkk + mod), sufnum - 1, mod) % mod) % mod;
			i64 p2 = (1 - p0 - p1 + mod + mod) % mod;
			std::cerr << "p" << p0 << " " << p1 << " " << p2 << '\n';
			dp[i][0] += dp[i - 1][0] * p0 % mod;
			dp[i][1] += (dp[i - 1][0] * p1 % mod + dp[i - 1][1] * p0 % mod) % mod;
			dp[i][2] += (dp[i - 1][0] * p2 % mod + dp[i - 1][1] * (p1 + p2) % mod + dp[i - 1][2]) % mod;
		}
		std::cerr << "mid" << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << '\n';
	};

	i64 sum = 0;
	bool full = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if (sum <= 80) {
			push_before(a[i], i);
		} else if (full) {
			push_after(a[i], i);
		} else {
			full = 1;
			sum -= a[i];
			i64 pre = 80 - sum, suf = sum + a[i] - 80;
			push_mid(pre, suf, i);
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << (dp[i][2] + dp[i - 1][1] * r % mod * inv(1000, mod) % mod) % mod << " \n"[i == n];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}