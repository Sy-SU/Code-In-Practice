#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	std::cin >> str;

	int ans = 0;
	for (int i = 1; i < (int)str.size(); i++) {
		ans += (str[i - 1] == '1' && str[i] == '0');
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}