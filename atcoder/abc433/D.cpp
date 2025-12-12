#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	i64 m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<std::map<int, i64>> cnt(11);

	for (int i = 1; i <= n; i++) {
		i64 base = 1, ind = 0;
		while (base <= a[i]) {
			base *= 10;
			ind++;
		}
		cnt[ind][a[i] % m]++;
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		i64 base = 1;
		for (int ind = 1; ind <= 10; ind++) {
			base *= 10;
			// b[i] + a[i] * base
			i64 need = (m - (a[i] % m * base % m)) % m;
			ans += cnt[ind][need];
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}