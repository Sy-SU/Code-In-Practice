#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 10;

void solve() {
	std::string str;
	std::cin >> str;

	int n = str.size();
	int ans = 1e9;
	for (int l = 0; l < n; l++) {
		for (int r = l + 1; r < n; r++) {
			// l ~ r
			auto check = [&]() -> bool {
				std::string s = str;
				std::vector<int> vis(n, 0);
				for (int i = l; i <= r; i++) {
					vis[i] = 1;
				}

				std::map<char, int> m;
				for (int i = 0; i < n / 2; i++) {
					if (vis[i] != 1 && vis[n - i - 1] != 1) {
						if (s[i] != s[n - i - 1]) {
							return 0;
						}
					} else {
						m[s[i]]++, m[s[n - i - 1]]--;
					}
				}
				if (n % 2 == 1 && vis[n / 2] == 1) {
					m
				}
			};

			if (check()) {
				ans = std::min(ans, r - l + 1);
			}
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