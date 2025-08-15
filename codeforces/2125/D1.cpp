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

struct SEG {
	int l, r;
	i64 p;
	bool operator > (const SEG &s) const {
		return (r == s.r ? l > s.l : r > s.r);
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<SEG> vec(n + 1);

	for (int i = 1; i <= n; i++) {
		int l, r;
		i64 p, q;
		std::cin >> l >> r >> p >> q;

		vec[i] = {l, r, p * inv(q, mod) % mod};
	}

	std::sort(vec.begin() + 1, vec.end(), [](SEG s1, SEG s2) {
		return (s1. l == s2.l ? s1.r < s2.r : s1.l < s2.l);
	});


	std::priority_queue<SEG, std::vector<SEG>, std::greater<SEG>> pq;

	int now = 1;
	i64 dp0 = 1, dp1 = 0;
	for (int i = 1; i <= m; i++) {
		while (vec[now].l <= i) {
			pq.push(vec[now]);
			i64 p = vec[now].p;

			i64 t0 = (1 - p + mod) % mod * dp0 % mod;
			i64 t1 = ((1 - p + mod) % mod * dp1 % mod + p * dp0 % mod) % mod;

			dp0 = t0, dp1 = t1;

			now++;
		}
		while (!pq.empty() && pq.top().r < i) {
			i64 p = pq.top().p;

			i64 t0 = inv((1 - p + mod) % mod, mod) * dp0 % mod;
			i64 t1 = inv((1 - p + mod) % mod, mod) * (dp1 - dp0 * p % mod * inv((1 - p + mod) % mod, mod) % mod + mod) % mod;

			dp0 = t0, dp1 = t1;

			pq.pop();
		}
		std::cout << dp1 << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}