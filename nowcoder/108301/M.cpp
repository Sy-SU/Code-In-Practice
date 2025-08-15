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

	std::sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= i; j++) {
			sum += a[j];
		}
		for (int j = 1; j <= i; j++) {
			a[j] = sum / i;
		}
	}

	std::cout << a[n] << '\n';
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