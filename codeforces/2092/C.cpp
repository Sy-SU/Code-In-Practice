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

	i64 sum = 0, oddcnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] % 2) {
			oddcnt++;
		}
		sum += a[i];
	}

	if (oddcnt == n || oddcnt == 0) {
		std::cout << *std::max_element(a.begin() + 1, a.end()) << '\n';
	} else {
		std::cout << sum - (oddcnt - 1) << '\n';
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