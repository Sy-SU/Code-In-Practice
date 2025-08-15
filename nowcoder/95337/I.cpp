#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	if (n == m) {
		std::cout << "Yes" << '\n';
		return;
	}

	if (n == 0 || m == 0) {
		std::cout << "No" << '\n';
		return;
	}

	std::cout << "Yes" << '\n';
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