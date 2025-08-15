#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, a, b;
	std::cin >> n >> a >> b;
	if (a % 2 != b % 2) {
		std::cout << "NO" << '\n';
	} else {
		std::cout << "YES" << '\n';
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