#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q, s;
	std::cin >> n >> q >> s;

	std::vector<int> sta(n + 2);
	sta[1] = s;
	for (int i = 1; i <= n; i++) {
		int t;
		std::cin >> t;

		sta[i + 1] = sta[i] + t;
	}

	while (q--) {
		int x, y;
		std::cin >> x >> y;

		std::cout << sta[x] + y - 1 << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}