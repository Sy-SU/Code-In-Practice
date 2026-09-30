#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p(n + 1), a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	
	std::vector<int> pri(n + 1);
	for (int i = 1; i <= n; i++) {
		pri[p[i]] = i;
	}

	for (int i = 2; i <= n; i++) {
		if (pri[a[i - 1]] > pri[a[i]]) {
			std::cout << "No" << '\n';
			return;
		}
	}
	std::cout << "Yes" << '\n';
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