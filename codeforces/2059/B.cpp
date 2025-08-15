#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int x = k / 2, lst = 0, cnt = 0;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (i > lst) {
			cnt++;
			lst = n - (x - cnt) * 2;
			continue;
		}
		for (int j = i; j <= lst; j++) {
			if (a[j] != (idx + 1)) {
				std::cout << idx + 1 << '\n';
				return;
			}
		}
		idx++;
	}
	std::cout << x + 1 << '\n';
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