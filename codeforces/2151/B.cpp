#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::string str;
	std::cin >> str;

	std::vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		std::cin >> a[i];
	}

	std::map<int, bool> vis;
	for (int i = 1; i <= m; i++) {
		vis[a[i]] = 1;
	}

	int now = 1;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'A') {
			now++;
		} else {
			now++;
			while (vis.count(now)) {
				now++;
			}
		}
		vis[now] = 1;
		if (str[i] == 'B') {
			while(vis.count(now)) {
				now++;
			}
		}
	}

	std::cout << vis.size() << '\n';
	for (auto [p, b] : vis) {
		if (b) {
			std::cout << p << " ";
		}
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