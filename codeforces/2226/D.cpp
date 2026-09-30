#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	int min = *std::min_element(a.begin() + 1, a.end());
	int max = *std::max_element(a.begin() + 1, a.end());

	if (min % 2 == max % 2) {
		std::cout << "YES" << '\n';
		return;
	}

	int t = 1 - (max % 2);

	int l = n + 1, r = -1;
	for (int i = 1; i <= n; i++) {
		
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