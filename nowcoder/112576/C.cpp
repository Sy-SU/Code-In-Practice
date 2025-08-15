#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> a[i];
	}

	std::map<int, int> to;
	std::vector<int> vis(n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		if (vis[a[i]] == 0) {
			vis[a[i]] = i;
		} else {
			to[a[i]] = i;
		}
	}

	int now = 1;
	while (1) {
		int t = to[a[now]];
		if (t == now) {
			std::cout << "No" << '\n';
			return;
		}

		now = t + 1;
		if (now > 2 * n) {
			std::cout << "Yes" << '\n';
			return;
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