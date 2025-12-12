#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> a(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> b(n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = a[2 * n + 1 - i] - a[i];
	}

	i64 ans = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += b[i];
	}

	std::vector<i64> o;
	for (int i = n; i >= 1; i--) {
		o.push_back(sum);
		sum -= b[i] * 2;
		b[i - 1] -= b[i];
	}

	std::reverse(o.begin(), o.end());
	for (auto ot : o) {
		std::cout << ot << " ";
	}
	std::cout << '\n';
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