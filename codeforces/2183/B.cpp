#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	for (int i = 0; i < k - 1; i++) {
		if (cnt[i] == 0) {
			std::cout << i << "\n";
			return;
		}
	}
	std::cout << k - 1 << '\n';
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