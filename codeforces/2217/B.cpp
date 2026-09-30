#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	
	std::vector<int> a(n + 1), p(k + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= k; i++) {
		std::cin >> p[i];
	}

	int ans = 0;

	int cnt = 0;
	for (int i = p[1] - 1; i >= 1; i--) {
		if (a[i] != a[p[1]] && a[i + 1] == a[p[1]]) {
			cnt++;
		}
	}

	ans = std::max(ans, cnt);

	cnt = 0;
	for (int i = p[1] + 1; i <= n; i++) {
		if (a[i] != a[p[1]] && a[i - 1] == a[p[1]]) {
			cnt++;
		}
	}
	// std::cerr << "cnt = " << cnt << '\n';

	ans = std::max(ans, cnt);

	std::cout << ans * 2 << '\n';
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