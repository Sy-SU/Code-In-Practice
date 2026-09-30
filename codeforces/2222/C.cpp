#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	auto b = a;
	std::sort(b.begin() + 1, b.end());

	int med = b[(n + 1) / 2];

	std::vector<int> lar(n + 1), low(n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] >= med) {
			lar[i] = 1;
		} 
		if (a[i] <= med) {
			low[i] = 1;
		}
	} 

	std::vector<int> dp(n + 1, -1e9), prelar(n + 1), prelow(n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		prelar[i] = prelar[i - 1] + lar[i];
		prelow[i] = prelow[i - 1] + low[i];

		// std::cerr << prelar[i] << " " << prelow[i] << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % 2 == j % 2) {
				int len = i - j + 1;
				if (prelar[i] - prelar[j - 1] >= (len + 1) / 2 && prelow[i] - prelow[j - 1] >= (len + 1) / 2) {
					dp[i] = std::max(dp[i], dp[j - 1] + 1);
				}
			}
		}
		// std::cerr << dp[i] << '\n';
	}

	std::cout << dp[n] << '\n';
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