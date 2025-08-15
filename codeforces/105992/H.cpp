#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	double x;
	std::cin >> x;

	std::cout << "Vivo" << " " << std::fixed << std::setprecision(3) << 50.0 * (x + 100) / 100 << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}