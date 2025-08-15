#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] == -1) {
			continue;
		}
		if (std::__gcd(a[i - 1], a[i]) != 1) {
			a[i] = -1;
			cnt++;
		}
	}

	std::cout << cnt << '\n';
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