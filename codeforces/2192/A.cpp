#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int ans = 1, ok = 0;
	for (int i = 1; i < n; i++) {
		ans += s[i] != s[i - 1];
		ok |= s[i] == s[i - 1];
	}
	if (s[0] != s[n - 1] && ok) {
		ans++;
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