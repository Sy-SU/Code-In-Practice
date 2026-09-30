#include <bits/stdc++.h>

using i64 = long long;

int B = 100000;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 2), b(n + 2);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<std::vector<std::pair<i64, int>>> dp(2);
	
	for (int v = 1; v <= b[1]; v++) {
		if (v == a[1]) {
			continue;
		}
		
	}

	dp[1].push_back({a[1], 0});

	for (int i = 2; i <= n; i++) {
		// dp[!(i & 1)] -> dp[i & 1]

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