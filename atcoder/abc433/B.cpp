#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		int ans = -1;
		for (int j = i - 1; j >= 1; j--) {
			if (a[j] > a[i]) {
				ans = j;
				break;
			}
		}
		std::cout << ans << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}