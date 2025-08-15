#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;
constexpr int mod = 998244353;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::vector<i64> a(n + 1, 0), b(n + 1, 0);	
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<i64> veca(n + 1, 0), vecb(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		veca[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		vecb[i] = b[i];
	}
	std::sort(veca.begin() + 1, veca.end());
	std::sort(vecb.begin() + 1, vecb.end());
	i64 mul = 1;
	for (int i = 1; i <= n; i++) {
		mul *= std::min(veca[i], vecb[i]);
		mul %= mod;
	}
	std::cout << mul << ' ';
	while (q--) {
		int o, x;
		std::cin >> o >> x;
		if (o == 1) {
			a[x]++;
		} else {
			b[x]++;
		}
		std::vector<i64> veca(n + 1, 0), vecb(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			veca[i] = a[i];
		}
		for (int i = 1; i <= n; i++) {
			vecb[i] = b[i];
		}
		std::sort(veca.begin() + 1, veca.end());
		std::sort(vecb.begin() + 1, vecb.end());
		i64 mul = 1;
		for (int i = 1; i <= n; i++) {
			mul *= std::min(veca[i], vecb[i]);
			mul %= mod;
		}
		std::cout << mul << " \n"[q == 0];
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