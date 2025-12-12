#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> cnt(4 * n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;

        cnt[x]++;
    }

    int ans = 0, lst = 1;
    for (int i = 1; i <= 4 * n; i++) {
        if (cnt[i] <= k) {
            ans = std::max(ans, i - lst);
            lst = i + 1;
        } else {
            cnt[i + 1] += cnt[i] - 1;
            cnt[i] = 1;
        }
    }

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