#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;

	std::string s;
	std::cin >> s;

	s = " " + s;

	int now = n;
	std::vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') {
			p[i] = now--;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			p[i] = now--;
		}
	}

	int maxlen = 0, len = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			len++;
		} else {
			maxlen = std::max(maxlen, len), len = 0;
		}
	}
	maxlen = std::max(maxlen, len);

	if (maxlen < k) {
		std::cout << "YES" << '\n';
		for (int i = 1; i <= n; i++) {
			std::cout << p[i] << " \n"[i == n];
		}
	} else {
		std::cout << "NO" << '\n';
	}
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