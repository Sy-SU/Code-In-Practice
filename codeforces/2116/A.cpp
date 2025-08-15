#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	if (std::min(a, c) >= std::min(b, d)) {
		std::cout << "Gellyfish" << '\n';
	} else {
		std::cout << "Flower" << '\n';
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