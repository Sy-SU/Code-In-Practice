#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::vector<int> a(4);
	for (int i = 0; i < 4; i++) {
		std::cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans += a[i] == (i + 1);
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}