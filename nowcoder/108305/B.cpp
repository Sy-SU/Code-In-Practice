#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 U = 1073741823;

void solve() {
	int n, A, B, C;
	std::cin >> n >> A >> B >> C;

	std::vector<i64> f(4), g(4), h(4); // f[i - 0], f[i - 1], f[i - 2], f[i - 3]
	f[0] = C & U, f[1] = B & U, f[2] = A & U;

	bool p = 0;
	for (int i = 0; i < n; i++) {
		i64 ng = f[2] ^ ((65536 * f[2]) & U);
		i64 nh = ng ^ (ng / 32);
		i64 nf = nh ^ ((2 * nh) & U) ^ f[1] ^ f[0];
		f[3] = f[2], f[2] = f[1], f[1] = f[0], f[0] = nf;
		g[3] = g[2], g[2] = g[1], g[1] = g[0], g[0] = ng;
		h[3] = h[2], h[2] = h[1], h[1] = h[0], h[0] = nh;

		// std::cerr << f[0] << "\n";
		p ^= (f[0] % (n - i) != 0);
	}
	std::cout << p;
	for (int i = n; i <= 4 * n - 3; i++) {
		i64 ng = f[2] ^ ((65536 * f[2]) & U);
		i64 nh = ng ^ (ng / 32);
		i64 nf = nh ^ ((2 * nh) & U) ^ f[1] ^ f[0];
		f[3] = f[2], f[2] = f[1], f[1] = f[0], f[0] = nf;
		g[3] = g[2], g[2] = g[1], g[1] = g[0], g[0] = ng;
		h[3] = h[2], h[2] = h[1], h[1] = h[0], h[0] = nh;

		i64 del = i - n;
		if (del % 3 == 0 && del > 0) {
			i64 l = std::min(f[3] % n, f[2] % n);
			i64 r = std::max(f[3] % n, f[2] % n);
			i64 d = f[1] % n + 1;

			p ^= (((r - l) % 2) & (d % 2));
			std::cout << p;
		}
		// std::cerr << f[0] << '\n';
	}
	std::cout << '\n';
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