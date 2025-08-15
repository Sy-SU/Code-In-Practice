#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	int ans = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = x + 1; y <= n; y++) {
			std::swap(a[x], a[y]);

			int cnt = 0;
			int fsta = 1, fstb = 1;
			for (int i = 1; i <= n; i++) {
				if (a[fsta] > b[fstb]) {
					fsta++, cnt++;
				} else {
					fstb++;
				}
			}
			ans = std::max(ans, cnt);

			std::swap(a[x], a[y]);
		}
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