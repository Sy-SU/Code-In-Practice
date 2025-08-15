#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int cnt0 = 0;
	for (int i = 1; i <= n; i++) {
		cnt0 += a[i] == 0;
	}

	int ans = n - cnt0;
	if (cnt0 != 0) {
		int pos = -1;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				pos = i;
				break;
			}
		}
		std::vector<int> b(n + 1);
		int idx = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] || i == pos) {
				b[++idx] = a[i];
			}
		}

		// for (int i = 1; i <= idx; i++) {
		// 	std::cerr << b[i] << " \n"[i == idx];
		// }

		bool isok = 1;
		std::vector<int> min(idx + 1, 1e9);
		for (int i = 1; i <= idx; i++) {
			// std::cerr << b[i] << " \n"[i == idx];
			min[i] = std::min(min[i - 1], b[i]);
		}
		// for (int i = 1; i <= idx; i++) {
		// 	std::cerr << min[i] << " \n"[i == idx];
		// }
		int mex = 0;
		std::map<int, bool> vis;
		for (int i = idx; i >= 2; i--) {
			vis[b[i]] = 1;
			while (vis[mex]) {
				mex++;
			}
			// std::cerr << min[i - 1] << " " << mex << '\n';
			if (min[i - 1] < mex) {
				isok = 0;
				break;
			}
		}

		ans += isok;
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