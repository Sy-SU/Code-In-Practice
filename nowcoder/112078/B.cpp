#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	int mul = 1;
	while (n) {
		mul *= (n % 10);
		n /= 10;
	}

	int x = sqrt(mul);

	for (int i = x - 1; i <= x + 1; i++) {
		if (i * i == mul) {
			std::cout << "YES" << '\n';
			return;
		}
	}

	std::cout << "NO" << '\n';
	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}