#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k, p, m;
	std::cin >> n >> k >> p >> m;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int cnt = 0, cost = 0;
	if (p <= k) {
		cnt++, cost += a[p];
	} else {
		cnt++, cost += a[p];
		std::vector<int> b;
		for (int i = 1; i <= p - 1; i++) {
			b.push_back(a[i]);
		}

		std::sort(b.begin(), b.end());
		for (int i = 0; i < p - k; i++) {
			cost += b[i];
		}

		if (cost > m) {
			cnt = 0;
			std::cout << cnt << '\n';
			return;
		}
	}
	int need = a[p];
	a[p] = 1e9;
	std::sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n - k; i++) {
		need += a[i];
	}

	cnt += (m - cost) / need;
	std::cout << cnt << '\n';
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