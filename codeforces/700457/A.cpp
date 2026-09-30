#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int n = s.size();
	s = " " + s;

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		bool H = 0, W = 0, WU = 0, WUT = 0;
		for (int j = i; j <= n; j++) {
			if (W && s[j] == 'h') {
				H = 1;
			}
			if (s[j] == 'w') {
				W = 1;
			}

			if (W && s[j] == 'u') {
				WU = 1;
			}

			if (WU && s[j] == 't') {
				WUT = 1;
			}

			if (WUT && H) {
				ans++;
			}
		}
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}