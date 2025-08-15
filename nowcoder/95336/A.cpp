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

	std::vector<i64> l(n + 1, 0), r(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> l[i] >> r[i];
	}

	i64 ans = 0;
	for (int i = 2; i <= n; i++) {
		i64 l1 = l[i - 1], r1 = r[i - 1], l2 = l[i], r2 = r[i];

		if (l1 > l2) {
			std::swap(l1, l2), std::swap(r1, r2);
		}

		if (r2 <= r1) {
			i64 A = r2 * (r2 + 1) % mod * (2 * r2 + 1) % mod * inv(6, mod) % mod;
			i64 B = (l2 - 1) * (l2) % mod * (2 * l2 - 1) % mod * inv(6, mod) % mod;
			i64 AdB = (A - B + mod) % mod;

			i64 C = (l1 + r1) * (l2 + r2) % mod * (r2 - l2 + 1) % mod * inv(2, mod) % mod;

			i64 D = (l1 * l1 + r1 * r1 + r1 - l1) % mod * inv(2, mod) % mod * (r2 - l2 + 1) % mod;

			i64 t_ans = (AdB - C + D + mod) % mod * inv(r1 - l1 + 1, mod) % mod * inv(r2 - l2 + 1, mod) % mod;

			ans = (ans + t_ans) % mod;
		} else {
			if (l2 >= r1) {
				i64 t_ans = (l2 + r2 - l1 - r1) * inv(2, mod) % mod;
				ans = (ans + t_ans) % mod;
			} else {
				i64 t_ans1 = 0, t_ans2 = 0;

				i64 A = r1 * (r1 + 1) % mod * (2 * r1 + 1) % mod * inv(6, mod) % mod;
				i64 B = (l2 - 1) * (l2) % mod * (2 * l2 - 1) % mod * inv(6, mod) % mod;
				i64 AdB = (A - B + mod) % mod;

				i64 C = (l1 + r1) * (l2 + r1) % mod * (r1 - l2 + 1) % mod * inv(2, mod) % mod;

				i64 D = (l1 * l1 + r1 * r1 + r1 - l1) % mod * inv(2, mod) % mod * (r1 - l2 + 1) % mod;

				t_ans1 = (AdB - C + D + mod) % mod * inv(r1 - l1 + 1, mod) % mod * inv(r1 - l2 + 1, mod) % mod;

				t_ans2 = (r1 + 1 + r2 - l1 - r1) * inv(2, mod) % mod;

				ans = (ans + t_ans1 * (r1 - l2 + 1) % mod * inv(r2 - l2 + 1, mod) % mod + t_ans2 * (r2 - r1) % mod * inv(r2 - l2 + 1, mod) % mod) % mod;
			}
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