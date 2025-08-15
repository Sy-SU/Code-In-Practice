#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> suf(n + 2), max(n + 1);
	for (int i = 1; i <= n; i++) {
		max[i] = std::max(max[i - 1], a[i]);
	}
	for (int i = n; i >= 1; i--) {
		suf[i] = suf[i + 1] + a[i];
	}

	for (int i = n; i >= 1; i--) {
		std::cout << (suf[i + 1] + max[i]) << " \n"[i == 1];
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