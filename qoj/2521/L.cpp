#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b;
	std::cin >> a >> b;

	if (a == 30) {
		std::cout << "Alice" << '\n';
		return;
	}

	if (b == 30) {
		std::cout << "Bob" << "\n";
		return;
	}

	if (a >= 21 && a - b >= 2) {
		std::cout << "Alice" << '\n';
		return;
	}

	if (b >= 21 && b - a >= 2) {
		std::cout << "Bob" << '\n';
		return;
	}

	std::cout << "Underway" << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}