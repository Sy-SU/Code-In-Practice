#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<i64> p(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}

	std::sort(p.begin() + 1, p.end(), std::greater<i64>());
	i64 ans = p[1] % mod;

	i64 mul = p[1] % mod;
	bool proc = 0;
	for (int i = 2; i + k - 2 <= n; i += k - 1) {
		bool isok = 1;
		for (int j = i; j <= i + k - 2; j++) {
			if (p[j] == 0) {
				isok = 0;
				break;
			}
		}

		if (isok) {
			for (int j = i; j <= i + k - 2; j++) {
				mul = (mul * p[j]) % mod;
			}
			proc = 1;
		} else {
			break;
		}
	}

	std::cout << (proc ? mul : ans) << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int t = 1;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}