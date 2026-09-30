#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> G(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            std::cin >> ch;

            G[i][j] = ch - '0';
        }
    }

    std::vector<std::vector<int>> ans(n + 1, std::vector<int>(m + 1, 1e9));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int x = i + 1; x <= n; x++) {
                for (int y = j + 1; y <= m; y++) {
                    if (G[i][j] + G[i][y] + G[x][j] + G[x][y] != 4) {
                        continue;
                    }
                    for (int a = i; a <= x; a++) {
                        for (int b = j; b <= y; b++) {
                            ans[a][b] = std::min(ans[a][b], (x - i + 1) * (y - j + 1));
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int o = (ans[i][j] >= 1e7 ? 0 : ans[i][j]);
            std::cout << o << " \n"[j == m];
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}