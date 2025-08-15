#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	// std::sort(a.begin() + 1, a.end());

	std::vector<int> cnt(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] >= 3) {
			cnt[i + 1] += cnt[i] - 2;
			cnt[i] = 2;
		}
		if (cnt[i] % 2 == 1) {
			std::cout << "No" << '\n';
			return;
		}
	}
	std::cout << "Yes" << '\n';
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