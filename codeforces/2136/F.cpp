#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int x = 316;

	int a = 100000 / x;
	std::cout << "? " << a * x << " ";
	for (int i = 1 ; i <= x; i++) {
		std::cout << i << " ";
		for (int j = 1; j < a; j++) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}

	int res;
	std::cin >> res;

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