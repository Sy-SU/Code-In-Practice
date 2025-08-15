#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	int now = 0;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	for (int i = 0; i < n; i++) {
		if ((now ^ a[i]) == 0) {
			if (i == n - 1) {
				std::cout << "impossible" << '\n';
				return;
			}
			std::swap(a[i], a[i + 1]);
		}
		now ^= a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " \n"[i == n - 1];
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