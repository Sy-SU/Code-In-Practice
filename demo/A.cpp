#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    i64 n, p;
    std::cin >> n >> p;

    i64 ans = 4;
    for (int i = 2; i <= n; i++) {
        ans = (ans * ans) % p;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}