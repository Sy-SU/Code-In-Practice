#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x;
	std::cin >> x;

	int cnt = 0;
	for (int i = x; i <= x + 500; i++) {
		int now = i;
		int d = 0;
		while (now) {
			d += now % 10;
			now /= 10;
		}
		if (i - d == x) {
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