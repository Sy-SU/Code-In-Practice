#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	s = " " + s + " ";

	while (k--) {
		int l, r;
		std::cin >> l >> r;

		int ans = 0;
		for (int i = l; i + 2 <= r; i++) {
			ans += s.substr(i, 3) == "xjx";
		}
		std::cout << ans << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}