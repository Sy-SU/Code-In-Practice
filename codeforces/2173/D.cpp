#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, k;
	std::cin >> n >> k;

	std::string s;
	while (n) {
		s += '0' + n % 2;
		n /= 2;
	}

	std::reverse(s.begin(), s.end());
	// std::cerr << s << '\n';

	int sz = s.size();
	int cnt0 = 0;
	for (int i = 0; i < sz; i++) {
		cnt0 += s[i] == '0';
	}

	if (k > cnt0) {
		std::cout << k + (sz - cnt0) - 1 << '\n';
		return;
	}

	// k
	s = " " + s;
	std::vector<int> pre0(sz + 1);
	for (int i = 1; i <= sz; i++) {
		pre0[i] = pre0[i - 1] + (s[i] == '0');
	}

	// std::cerr << s << '\n';

	std::vector<std::vector<int>> dp(sz + 1, std::vector<int>(k + 1));
	for (int i = 1; i <= sz; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int l = 1; l <= i; l++) {
				// l ~ i
				int cost = pre0[i] - pre0[l - 1] + 1;
				if (cost <= j) {
					dp[i][j] = std::max(dp[i][j], dp[l - 1][j - cost] + i - l + 1);
					// std::cerr << "dp" << i << " " << j << " = " << dp[i][j] << '\n';
				}
			}
		}
	}

	int p = 0;
	for (int i = 0; i <= k; i++) {
		p = std::max(p, dp[sz][i]);
	}

	std::cout << p << '\n';
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