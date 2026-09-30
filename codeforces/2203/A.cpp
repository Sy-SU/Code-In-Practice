#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m, d;
	std::cin >> n >> m >> d;

	int x = d / m;
	int y = (n + x) / (x + 1);

	std::cout << y << '\n';
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