#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> vis(n + 1);

	std::vector<std::vector<int>> vec;
	for (int i = 2; i <= n; i++) {
		if (vis[i]) {
			continue;
		}
		std::vector<int> v;
		int now = i;
		while (now <= n) {
			if (vis[now] == 0) {
				v.push_back(now);
				vis[now] = 1;
			}

			bool ok = 1;
			for (int k = 2; k <= n / now; k++) {
				if (vis[now * k] == 0) {
					now *= k;
					ok = 0;
				}
			}
			if (ok) {
				break;
			}
		}
		vec.push_back(v);
	}

	vec.push_back({1});

	for (auto ve : vec) {
		for (auto num : ve) {
			std::cout << num << " ";
		}
		std::cout << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}