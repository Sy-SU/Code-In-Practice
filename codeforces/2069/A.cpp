#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(n + 1);
	for (int i = 2; i <= n - 1; i++) {
		std::cin >> b[i];
	}

	for (int i = 2; i + 2 <= n - 1; i++) {
		if (b[i] == 1 && b[i + 1] == 0 && b[i + 2] == 1) {
			std::cout << "NO" << '\n';
			return;
		}
	}
	std::cout << "YES" << '\n';
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