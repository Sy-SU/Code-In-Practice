#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n1, t1, n2, t2;
	std::cin >> n1 >> t1 >> n2 >> t2;

	if (n1 == n2) {
		std::cout << (t1 < t2 ? "\"\\n\"" : "\"\\t\"");
	} else {
		std::cout << (n1 > n2 ? "\"\\n\"" : "\"\\t\"");
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}