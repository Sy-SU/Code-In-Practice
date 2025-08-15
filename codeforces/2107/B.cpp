#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	i64 k;
	std::cin >> n >> k;

	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 max = *std::max_element(a.begin() + 1, a.end()), min = *std::min_element(a.begin() + 1, a.end());
	if (max - min >= k + 2) {
		std::cout << "Jerry" << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] == max) {
			a[i]--;
			break;
		}
	}

	max = *std::max_element(a.begin() + 1, a.end()), min = *std::min_element(a.begin() + 1, a.end());

	if (max - min >= k + 1) {
		std::cout << "Jerry" << '\n';
		return;
	}

	i64 sum = 1;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}

	std::cout << (sum % 2 ? "Tom" : "Jerry") << '\n';
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