#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	i64 ans = 0, v = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '0') {
			v += 10;
			ans += v;
		} else if (str[i] == '1') {
			v = std::max(v - 5, 0ll);
			ans += v;
		} else {
			ans += std::max(v - 10, 0ll);
		}
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}