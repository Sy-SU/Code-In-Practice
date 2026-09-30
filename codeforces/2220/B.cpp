#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> a(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int max = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			max = std::max(max, cnt);
			cnt = 1;
		} else {
			cnt++;
		}
	}
	max = std::max(max, cnt);

	std::cout << (max < m ? "YES" : "NO") << '\n';
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