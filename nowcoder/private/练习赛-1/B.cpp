#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
	i64 n, s;
	std::cin >> n >> s;
 
    i64 ans = s - 1;
    for (int x = n / s; x <= n / s + 1; x++) {
        ans = std::min(ans, x + std::abs(n / x - s));
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