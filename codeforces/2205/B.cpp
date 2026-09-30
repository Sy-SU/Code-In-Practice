#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 k = 1;
	i64 n;

	std::cin >> n;

	for (int i = 2; i * i <= n; i++) {
		bool isok = 0;
		while (n % i == 0) {
			n /= i;
			isok = 1;
		}
		if (isok) {
			k *= i;
		}
	}

	if (n > 1) {
		k *= n;
	}

	std::cout << k << '\n';
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