#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	// std::sort(a.begin() + 1, a.end());

	std::map<int, int> p, vis;
	for (int i = 1; i <= n; i++) {
		p[a[i]] = 1;
	}

	std::vector<int> b;
	for (auto [num, sta] : p) {
		if (sta == 0 || vis[num] == 1) {
			continue;
		}
		if (k / num > n) {
			std::cout << -1 << '\n';
			return;
		}
		for (int j = 2; j * 1ll * num <= k; j++) {
			if (p[j * 1ll * num] == 0) {
				std::cout << -1 << '\n';
				return;
			}
			vis[j * 1ll * num] = 1;
		}
		b.push_back(num);
		vis[num] = 1;
	}

	std::cout << b.size() << '\n';
	for (auto num : b) {
		std::cout << num << " ";
	}
	std::cout << '\n';
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