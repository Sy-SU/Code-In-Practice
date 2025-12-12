#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b;
	std::cin >> a >> b;

	if (a + b == 350234) {
		std::cout << "They are truly destined brothers" << '\n';
	} else {
		std::cout << "Nanshan and Beihai are not meant to be" << '\n';
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