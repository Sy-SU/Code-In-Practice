#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	while (1) {
		int n;
		std::cin >> n;

		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
		}

		int q;
		std::cin >> q;
		while (q--) {
			int W;
			std::cin >> W;

			int l = 1, s = 0;
			for (int i = 1; i <= n; i++) {
				if (s + a[i] > W) {
					s = a[i], l++;
				} else {
					s += a[i];
				}
			}
			std::cout << "ans = " << l << std::endl;
		}
	}

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