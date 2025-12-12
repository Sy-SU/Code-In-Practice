#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	auto t = s;

	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			for (int j = 1; j <= k && (i + j) < n; j++) {
				t[i + j] = '1';
			}
		}
	}

	// std::cerr << t << '\n';

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += t[i] == '0';
	}
	std::cout << cnt << '\n';
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