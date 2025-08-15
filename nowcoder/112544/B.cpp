#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	int min = 200, max = 0;
	for (int i = 0; i < n; i++) {
		max = std::max(max, (int)str[i]);
		min = std::min(min, (int)str[i]);
	}

	std::cout << max - min + 1 << '\n';
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