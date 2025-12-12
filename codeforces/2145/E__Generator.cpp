#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << 1 << '\n';

    int n = 200000;
    std::cout << n << '\n';

    for (int i = 1; i <= n; i++) {
        if (i <= 10) {
            std::cout << (i % 2 ? 'a' : 'b');
        } else {
            std::cout << (i % 2 ? 'b' : 'a');
        }
    }
    std::cout << '\n';

    return 0;
}
