#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;

	std::cout << ((b + c == a) ? "YES" : "NO") << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}