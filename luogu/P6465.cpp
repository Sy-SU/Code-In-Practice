#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, l;
	std::cin >> n >> l;

	std::vector<int> c(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	l = std::max(2, l);

	
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