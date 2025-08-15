#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> b(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> sufgcd(n + 2);
	for (int i = n; i >= 1; i--) {
		sufgcd[i] = std::__gcd(sufgcd[i + 1], b[i]);
	}

	int x = 1;

	auto lcm = [&](int q, int w) -> int {
		return q / std::__gcd(q, w) * w;
	};

	for (int i = 1; i <= n - 1; i++) {
		// if (sufgcd[i + 1] % b[i]) {
		// 	x = lcm(x, b[i] / std::__gcd(b[i], sufgcd[i + 1]));
		// 	// std::cerr << x <<" " << b[i] << " " << sufgcd[i + 1] << '\n';
		// }
		x = lcm(x, b[i] / std::__gcd(b[i], sufgcd[i + 1]));
	}

	std::cout << x << '\n';
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