#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e3 + 10;

void solve() {
    std::string a, b;
    std::cin >> a >> b;
    int na = a.size(), nb = b.size();

    a = " " + a, b = " " + b;
    std::vector<std::vector<int>> dp(na + 1, std::vector<int>(nb + 1, 1e9));

    for (int i = 1; i <= na; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= nb; i++) {
        dp[0][i] = i;
    }
    dp[0][0] = 0;
    
    for (int i = 1; i <= na; i++) {
        for (int j = 1; j <= nb; j++) {
            // std::cerr << a[i] << " " << b[j] << '\n';
            if (a[i] == b[j]) {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
            } else {
                // std::cerr << dp[i][j] << " " << dp[i][j - 1] << " " << dp[i - 1][j] << '\n';
                dp[i][j] = std::min({dp[i][j], dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1});
            }
        }
    }
    std::cout << dp[na][nb] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}