#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::set<int> s;
	for (int i = 1; i <= 1000; i++) {
		int x = i;
		for (int j = 2; j * j <= x; j++) {
			while (x % (j * j) == 0) {
				x /= j * j;
			}
		}
		s.insert(x);
		std::cerr << i << " " << x << '\n';
	}
	std::cout << s.size() << '\n';
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