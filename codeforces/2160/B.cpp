#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::map<int, int> lst;
	lst[0] = 0;

	std::vector<int> a(n + 1);

	int max = 0;
	for (int i = 1; i <= n; i++) {
		i64 del = b[i] - b[i - 1];
		a[i] = a[i - del];
		if (a[i] == 0) {
			a[i] = max + 1;
		}
		max = std::max(a[i], max);
	}

	for (int i = 1; i <= n; i++) {
		std::cout << a[i] << " \n"[i == n];
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