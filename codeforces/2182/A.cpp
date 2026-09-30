#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int cnt5 = 0, cnt6 = 0;
	for (int i = 0; i + 4 <= n; i++) {
		if (s.substr(i, 4) == "2025") {
			cnt5++;
		}
		if (s.substr(i, 4) == "2026") {
			cnt6++;
		}
	}

	if (cnt5 >= 1) {
		if (cnt6 >= 1) {
			std::cout << 0 << "\n";
			return;
		}
		std::cout << 1 << '\n';
		return;
	}
	std::cout << 0 << '\n';
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