#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1e6 + 10;

void solve() {
	int n, x;
	std::cin >> n >> x;
	
	std::vector<i64> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}	
	
	i64 ans = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] + a[i - 1] > x) {
			ans += (a[i] + a[i - 1] - x);
			a[i] -= (a[i] + a[i - 1] - x);
			if (a[i] < 0) {
				a[i - 1] += a[i], a[i] = 0;
			}
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	solve();
	
	return 0;
} 
