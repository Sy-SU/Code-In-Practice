#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

int ask(int l, int r) {
	std::cout << "? " << l << " " << r << std::endl;
	int res;
	std::cin >> res;
	return res;
}

void find(int k) {
	std::cout << "! " << k << std::endl;
}

void solve() {
	
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