#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<i64> a(n + 1), b(m + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}

	std::sort(b.begin() + 1, b.end());
	int ptr = 1;

	i64 min = -1e18;
	for (int i = 1; i <= n; i++) {
		while (ptr <= m && b[ptr] - a[i] < min && a[i] >= b[ptr] - a[i]) {
			ptr++;
		}
		if (ptr == m + 1) {
			if (a[i] < min) {
				std::cout << "NO" << '\n';
				return;
			}
			min = a[i];
			
		} else {
			i64 a1 = std::min(a[i], b[ptr] - a[i]), a2 = std::max(a[i], b[ptr] - a[i]);
			if (a1 >= min) {
				min = a1;
			} else if (a2 >= min) {
				min = a2;
			} else {
				std::cout << "NO" << '\n';
				return;
			}
		}
		std::cerr << min << " \n"[i == n];
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