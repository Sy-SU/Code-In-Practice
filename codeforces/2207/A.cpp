#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int cnt = 0;
	for (auto ch : s) {
		if (ch == '1') {
			cnt++;
		}
	}

	// std::cerr << cnt << '\n';

	int max = cnt;
	for (int i = 1; i < n; i++) {
		if (s[i] == '0' && s[i - 1] == '1' && s[i + 1] == '1') {
			max++;
			s[i] = '1';
		}
	}

	// std::cerr << s << '\n';

	int min = max;

	for (int i = 1; i < n; i++) {
		if (s[i] == '1' && s[i - 1] == '1' && s[i + 1] == '1') {
			min--;
			s[i] = '0';
		}
	}

	std::cout << min << " " << max << '\n';
	// std::cout << cnt - min << " " << cnt + max << '\n';
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