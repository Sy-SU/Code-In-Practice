#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> a;
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			a.push_back(b[i]);
		}
	}

	int cnt = n;
	n = a.size();
	i64 ans = n;
	i64 sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	ans = std::min(ans, sum - cnt + 1);
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