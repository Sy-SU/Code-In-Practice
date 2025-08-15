#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::set<int> s;
	for (int i = 1; i <= n; i++) {
		if (a[i] != -1) {
			s.insert(a[i]);
			if (a[i] == 0) {
				std::cout << "No" << '\n';
				return;
			}
		}
	}

	if (s.size() >= 2) {
		std::cout << "No" << '\n';
	} else {
		std::cout << "Yes" << '\n';
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