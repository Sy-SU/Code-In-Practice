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
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1), q(n + 1);
	for (int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> q[i];
	}

	int maxp = 0, mxpi = 0;
	int maxq = 0, mxqi = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] > maxp) {
			maxp = p[i];
			mxpi = i;
		}
		if (q[i] > maxq) {
			maxq = q[i];
			mxqi = i;
		}

		if (p[mxpi] > q[mxqi]) {
			std::cout << (qpow(2, p[mxpi], mod) + qpow(2, q[i - mxpi], mod)) % mod << " \n"[i == n - 1];
		} else if (p[mxpi] < q[mxqi]) {
			std::cout << (qpow(2, q[mxqi], mod) + qpow(2, p[i - mxqi], mod)) % mod << " \n"[i == n - 1];		
		} else {	
			if (q[i - mxpi] > p[i - mxqi]) {
				std::cout << (qpow(2, p[mxpi], mod) + qpow(2, q[i - mxpi], mod)) % mod << " \n"[i == n - 1];
			} else {
				std::cout << (qpow(2, q[mxqi], mod) + qpow(2, p[i - mxqi], mod)) % mod << " \n"[i == n - 1];
			}
		}

	}

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