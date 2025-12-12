#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += str[i] == '0';
	}

	int ans = 0;
	for (int i = 0; i < cnt; i++) {
		if (str[i] == '1') {
			ans++;
		}
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