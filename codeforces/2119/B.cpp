#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	i64 px, py, qx, qy;
	std::cin >> px >> py >> qx >> qy;

	i64 sum = 0, max = 0;
	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		sum += a[i];
		max = std::max(max, a[i]);
	}

	i64 dist = (px - qx) * (px - qx) + (py - qy) * (py - qy);

	if (n == 1) {
		std::cout << (dist == sum * sum ? "Yes" : "No") << "\n";
		return;
	}

	// if (n == 2) {
	// 	std::cout << ((dist <= sum && dist >= std::abs(a[1] - a[2]) * std::abs(a[1] - a[2])) ? "Yes" : "No") << '\n';
	// 	return;
	// }

	if (dist <= sum * sum && (2 * max <= sum || dist >= (2 * max - sum) * (2 * max - sum))) {
		std::cout << "Yes" << '\n';
	} else {
		std::cout << "No" << '\n';
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