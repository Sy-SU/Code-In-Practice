#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	std::cin >> str;

	int sz = str.size();
	for (int i = 0; i + 1 < sz; i++) {
		if (str[i] == '9' && str[i + 1] == '9') {
			std::cout << "YES" << '\n';
			return;
		}
	}
	std::cout << "NO" << '\n';
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