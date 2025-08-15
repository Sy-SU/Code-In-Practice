#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(n + 1, 0), b(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	i64 cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) {
			cnt++;
		}
	}

	if (cnt == 0) {
		std::cout << "YES" << '\n';
		return;
	}
	if (cnt >= 2) {
		std::cout << "NO" << '\n';
		return;
	}

	int del = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < b[i]) {
			del = b[i] - a[i];
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] >= b[i]) {
			if (a[i] - b[i] < del) {
				std::cout << "NO" << '\n';
				return;
			}
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