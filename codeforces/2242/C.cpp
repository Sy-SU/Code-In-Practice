#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	std::vector<int> b(n + 1);
	for (int i = 1; i <= n; i++) {
		b[cnt[i]]++;
	}

	// for (int i = 1; i <= n; i++) std::cerr << b[i] << '\n';

	int ans = 0, sum = n, var = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] != 0) {
			var++;
		}
	}

	for (int x = 1; x <= n; x++) {
		if (var == 0) {
			break;
		}
		// std::cerr << "X = " << x << '\n';
		// std::cerr << "res number = " << sum << '\n';
		// std::cerr << "var = " << var << '\n';
		if (b[x] != 0) {
			if (sum <= k) {
				if ((k - sum) % var == 0) {
					ans++;
				}
			}
		}
		

		sum -= var;
		var -= b[x];
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