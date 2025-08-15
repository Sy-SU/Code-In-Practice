#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	str = "0" + str;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += str[i] != str[i - 1];
	}

	int ans = n + cnt;

	if (cnt == 2) {
		ans--;
	}
	if (cnt >= 3) {
		ans -= 2;
	}

	std::cout << ans << '\n';
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