#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> h(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> h[i];
	}

	std::vector<i64> need(n + 1);

	int q;
	std::cin >> q;
	while (q--) {
		i64 x;
		std::cin >> x;

	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}