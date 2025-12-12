#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	bool isok = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] % 2 != a[1] % 2) {
			isok = 1;
		}
	}

	if (isok) {
		std::sort(a.begin() + 1, a.end());
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