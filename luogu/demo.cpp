#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    a[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j =  1; j <= i; j++) {
            std::cout << a[i][j] << " \n"[j == i];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}