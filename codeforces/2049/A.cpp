#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int condi = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			condi = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] != 0 && a[i - 1] == 0) {
			cnt++;
		}
	}

	if (cnt >= 2) {
		condi = 2;
	}

	std::cout << condi << '\n';
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