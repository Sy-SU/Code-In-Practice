#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	i64 sum = 0;
	for (int i = 1; i <= n; i++) {
		i64 x;
		std::cin >> x;
		sum += x;
	}

	i64 ans = 1e9;
	for (i64 i = 0; i <= 500; i++) {
		for (i64 j = 0; j <= 500; j++) {
			for (i64 k = 0; k <= 500; k++) {
				if (i + j + k == sum) {
					ans = std::min(ans, i | j | k);
				}
			}
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}