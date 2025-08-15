#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	s = " " + s;

	int cnt0 = 0;
	for (int i = 1; i <= n; i++) {
		cnt0 += s[i] == '0';
	}

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 orgsum = 0, organs = -1e18;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			orgsum = std::max(a[i], orgsum + a[i]);
		} else {
			orgsum = 0;
		}
		organs = std::max(organs, orgsum);
	}

	if (organs > k) {
		std::cout << "No" << '\n';
		return;
	}

	if (cnt0 == 0) {
		i64 maxsum = 0;
		for (int i = 1; i <= n; i++) {
			maxsum = std::max(a[i], a[i] + maxsum);
		}
		if (maxsum == k) {
			std::cout << "Yes" << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << a[i] << " \n"[i == n];
			}
		} else {
			std::cout << "No" << '\n';
		}
		return;
	}

	std::vector<i64> suf(n + 2);
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + a[i];
	}

	if (cnt0 == 1) {
		std::vector<i64> dp(n + 2);
		int pos0 = -1;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0') {
				pos0 = i;
				break;
			}
		}

		for (int i = 1; i < pos0; i++) {
			dp[i] = std::max(a[i], a[i] + dp[i - 1]);
		}
		for (int i = n; i > pos0; i--) {
			dp[i] = std::max(a[i], a[i] + dp[i + 1]);
		}

		a[pos0] = k - std::max(0ll, dp[pos0 - 1]) - std::max(0ll, dp[pos0 + 1]);

		i64 maxsum = 0, maxans = -1e18;
		for (int i = 1; i <= n; i++) {
			maxsum = std::max(a[i], a[i] + maxsum);
			maxans = std::max(maxans, maxsum);
		}
		if (maxans == k) {
			std::cout << "Yes" << '\n';
			for (int i = 1; i <= n; i++) {
				std::cout << a[i] << " \n"[i == n];
			}
		} else {
			std::cout << "No" << '\n';
		}
		return;
	}

	int pos0 = -1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') {
			pos0 = i;
			break;
		}
	}

	for (int i = pos0 + 1; i <= n; i++) {
		if (s[i] == '0') {
			a[i] = -1e16;
		}
	}

	std::vector<i64> dp(n + 2);

	for (int i = 1; i < pos0; i++) {
		dp[i] = std::max(a[i], a[i] + dp[i - 1]);
	}
	for (int i = n; i > pos0; i--) {
		dp[i] = std::max(a[i], a[i] + dp[i + 1]);
	}

	a[pos0] = k - std::max(0ll, dp[pos0 - 1]) - std::max(0ll, dp[pos0 + 1]);

	std::cout << "Yes" << '\n';
	for (int i = 1; i <= n; i++) {
		std::cout << a[i] << " \n"[i == n];
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