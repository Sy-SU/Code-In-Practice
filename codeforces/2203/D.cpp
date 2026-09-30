#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}

	i64 lcm = a[1];
	for (int i = 1; i <= n; i++) {
		lcm = a[i] * lcm / std::gcd(a[i], lcm);
		if (lcm >= 1e9) {
			lcm = 1e12;
		}
	}

	int cntA = 0, cntB = 0, cntAB = 0;
	for (int i = 1; i <= m; i++) {
		if (b[i] % lcm == 0) {
			cntA++; // 只有 Alice 可以拿
			// std::cerr << "Only Alice : " << b[i] << '\n';
		}
	}

	std::vector<int> oka(n + m + 1);
	for (int i = 1; i <= n; i++) {
		oka[a[i]] = 1;
	}

	std::vector<int> okb(n + m + 1);
	for (int i = 1; i <= n + m; i++) {
		if (oka[i]) {
			for (int j = 1; i * j <= n + m; j++) {
				okb[i * j] = 1;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		if (okb[b[i]] == 0) {
			cntB++;
			// std::cerr << "Only Bob : " << b[i] << '\n';
		}
	}

	cntAB = m - cntA - cntB;

	int A = cntA + (cntAB + 1) / 2, B = cntB + cntAB / 2;

	std::cout << (A > B ? "Alice" : "Bob") << '\n';
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