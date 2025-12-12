#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::sort(a.begin() + 1, a.end(), std::greater<int>());

	int have = 0;
	for (int i = 1; i <= n; i++) {
		if ((have + a[i] - i) / k < n - i) {
			have += a[i];
		} else {
			have++;
			int x = std::max(0, k * (n - i) + i - have);
			have += x;
			break;
		}
	}
	std::cout << have << '\n';
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